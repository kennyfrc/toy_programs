# TCP socket is part of the standard library (socket)
# this is a rack-based web server
# rack [wizgy - python port]is just a set of $specifications / $protocol that tells how the $server and the application $framework should #talk to each other
# - example: $rack will #tell the $server to $send_back $request_headers as http_<header_name>, / console doesn't capitalize and add HTTP_prefix
# - to #pass paht in $path_info, 
# - to #pass method in $request_method
# - to #pass $body as an IO in $rack.input
# these specifications are told by rack because we need to follow this to be able to host rack-based applications
# rack also tells teh app/framework to:key => "value", 
# - return [status, headers, body]
# - body must respond to #each
# - body can have a #close method
require "socket"
require "http/parser"
require "stringio"

# internet is a $series_of_tubes and we are building a small chunk of it
class Tube
  # create a $server_socket that will be reponsible for #accepting the $connection
  # this is where we initialize the $socket
  # my $server will #connect to a $port and here is where i will create my $socket
  def initialize(port, app)
    # TCPServer is a server socket class
    # two types of socket: TCP or UDP
    # TCP: connection full (all traffic )
    # UDP: for a streaming server | stats server = has no guarantee of deliverability of the packets
    @server = TCPServer.new(port) # this is the SERVER SOCKET
    @app = app # now we have access to the rack application instance inside our Connection 
  end

  # most the code for the server is here
  def start
    # the above only accepts 1 requiest. it will stop after receiving a request
    # in order to enable the server to accept more than 1 request, you need to create a loop
    loop do
      # this is an infinite loop.. this can now accept multiple vars and it will ahve separate objects per request
    # once the server socket is ready..
    # we need to tell the server socket that we're ready to accept a connection
    # the #accept method accepts the next incoming connection or it will block if there are no incoming connections at teh moment
    # it will #accept once it arrives
    # this is the socket / connetiont at we have to teh remote browser
    socket = @server.accept # THIS IS THE CLIENT SOCKET
    puts "this is the socket var: " + @socket.inspect
    # create a new isntance of the connneciton class
    connection = Connection.new(socket, @app) # now we have access to the rack application instance inside our Connection 
    connection.process
    end
  end

  #refactoring : move all connection logic that is related to handling 1 connection to this class
  class Connection
    # where do we get $socket? it is taken from the earlier initailizeations (socket = @server.accept)
    def initialize(socket, app)
      @socket = socket # CLIENT SOCKET
      @app = app # now we have access to the rack application instance inside our Connection 
      # create a new instance of that http::parser
      # the object passed is the $string that contains te callback (on_message_compelte)
      @parser = Http::Parser.new(self) # it's the parser's job to call that method once it fully receives the request
    end

    def process
      # this handles requests that are more than 1kb..
      # by iterating the method a bunch of times UNTIL it gets closed
      # this will keep on parsing parsing parsing
      until @socket.closed? || @socket.eof? # eof? == no more data
        # read some data 
        # there are multiple ways to read from a socket or from an I/O in ruby
        # read => in ruby, f you pass an integer argument to the #read method, ruby will #block till taht specific amount of bytes arrive in the socket
        # since we want to read as the data comes, which can be done by #readpartial (even if it's just 1kb of data, it will still read the data)
        data = @socket.readpartial(1024)
        # once it's done feeding data (ie. throught accept)
        @parser << data
          # the data is displayed is the following:
          # GET / HTTP/1.1
          # Host: localhost:3000
          # User-Agent: curl/7.43.0
          # Accept: */*
      end
    end

    def on_message_complete
      puts "This is the Parser's HTTP Method: #{@parser.http_method} || And this is the Parser's Request Path: #{@parser.request_path}"
      puts "This is the Parser's Headers: " + @parser.headers.inspect
      # @parser.headers.inspect is basically a full ruby object that we can play with
      # this is the information that we #pass to Rails
      puts "\r\n"


      # change it to make it compliant. use env
      env = {}
      @parser.headers.each_pair do |name, value|
        # error that we got the parser are the errors that we get from the browser or curl
        # User-Agent => USER_AGENT (and add http_) / this is the outcome that you want to deliver
        name = "HTTP_" + name.upcase.tr("-", "_")
        env[name] = value
      end
      # pass the request path
      env["PATH_INFO"] = @parser.request_path #rack requries us to pass the path into path info
      env["REQUEST_METHOD"] = @parser.http_method # checks what method isneeded
      env["rack.input"] = StringIO.new # rack requires us even there's no body || our server will not going to support having a body... let's not support that yet / /usually the body is stored here # StirigIO makes a string behave like an IO file => why: rack.input is required by the rack specification to be an IO object

      # we move this because we want this to work only once we have fully received the request
      send_response env # pass the env here
    end

    REASONS = {
      200 => "OK",
      404 => "Not found"
    }


    def send_response(env) # make sure that the function takes in the argument
      status, headers, body =  @app.call(env) # triggers the response / array of tree items
      reason = REASONS[status]
      # get ready to call the rack application
      #write back to the socket (or these are teh *responses*)
      # \r\n is how you end each line in an HTTP response || \r is a carriage return, like the one in a typewriter || it's almost just like a newline
      @socket.write "HTTP/1.1 #{status} #{reason} \r\n"
      # write all the headers
      # headers.each do | header | puts "#{header[0]}: #{header[1]}" end
      headers.each_pair do | name, value| 
        @socket.write "#{name}: #{value}\r\n"
      end
      @socket.write "\r\n" #if you remove this, then there will be no "hello"
      
      body.each do | chunk | 
        @socket.write chunk # dont forget to write it into the socket
      end
      # the above is just an http reponse

      body.close if body.respond_to? :close

      close
    end

    def close
      # this says tot he browser that we're done sending the reponse
      @socket.close
    end
  end


  # why create this? so that when we are inside the config.ru file, we run App.new inside the rack-based application, we call the run method inside the builder class so that we know which object is the rack application
  class Builder
    attr_reader :app

    def run(app)
      @app = app
    end

    def self.parse_file(file) # file == config.ru || this is an instance eval method
      # instead of using the App class, use the instance_eval instead
      content = File.read(file)
      builder = self.new
      builder.instance_eval(content) # this evaluates the config.ru in the context of builder
      builder.app
    end
  end
end




# you will find this at the $root of your Rails and Sinatra Application (something like this)
# this is the rack application that we want to serve in our web server
# all methods have this method call. sinatra and rails has this. otherwise, they won't be able to host themselves in a rack-based application serve
class App
  def call(env) # this si the body that we want tot send back
    message = "Hello from the tube.\n"
    [
      200, # status code
      { 'Content-Type' => 'text/plain', 'Content-Length' => message.size.to_s },
      [message]
    ]
  end
end



# create an instance of the tube class you just crated
# how do you run this? 
# go to the terminal and run the server
# create a new pane in the terminal and send an HTTP request via curl (or through a browser request)
app = Tube::Builder.parse_file("config.ru") # parse_file will parse the config.ru file
server = Tube.new(3000, app) # runs on port 3000 # pass the app argument in the Tube serever to host the application
puts "Plugging tube into port 3000 | #{server}"
server.start


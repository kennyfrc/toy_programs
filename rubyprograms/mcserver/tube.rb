# TCP socket is part of the standard library (socket)
require "socket"

# internet is a $series_of_tubes and we are building a small chunk of it
class Tube
  # create a $server_socket that will be reponsible for #accepting the $connection
  # this is where we initialize the $socket
  # my $server will #connect to a $port and here is where i will create my $socket
  def initialize(port)
    # TCPServer is a server socket class
    # two types of socket: TCP or UDP
    # TCP: connection full (all traffic )
    # UDP: for a streaming server | stats server = has no guarantee of deliverability of the packets
    @server = TCPServer.new(port)
    puts "#initialize: this is the #{@server.inspect}"
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
    socket = @server.accept
    puts "this is the socket var: #{socket}"
    # read some data 
    # there are multiple ways to read from a socket or from an I/O in ruby
    # read => in ruby, f you pass an integer argument to the #read method, ruby will #block till taht specific amount of bytes arrive in the socket
    # this sucks.. since we want to read as the data comes, which can be done by #readpartial (even if it's just 1kb of data, it will still read the data)
    data = socket.readpartial(1024)
    puts data

    #write back to the socket (or these are teh *responses*)
    # \r\n is how you end each line in an HTTP response || \r is a carriage return, like the one in a typewriter || it's almost just like a newline
    socket.write "HTTP/1.1 200K \r\n"
    socket.write "\r\n" #if you remove this, then there will be no "hello"
    socket.write "hello\n"
    # the above is just an http reponse

    # this says tot he browser that we're done sending the reponse
    socket.close
    end
  end
end

# create an instance of the tube class you just crated
# how do you run this? 
# go to the terminal and run the server
# create a new pane in the terminal and send an HTTP request via crul
server = Tube.new(3000) # runs on port 3000
puts "Plugging tube into port 3000 | #{server}"
server.start
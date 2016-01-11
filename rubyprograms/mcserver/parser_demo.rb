# require the http/parser std library

# purpose: we have huge amounts of data from the socket in tube_final.rb.. so we need ot make sense of the data 
# you do this through a praser that will extract information from there it will return smaller objects

require "http/parser"

class ParserDemo
  # create a new isntance of HTTP::Parser
  def initialize
    # it's a ruby wrapper aroudn the same HTTP parser as node.js
    # the argument that we pass here is the object that will #contain the $callbacks
    # this knows that once it's doen receiving the requests, it calls the callback-> #on_message_complete
    @parser = Http::Parser.new(self)
  end

  def on_message_complete
    # prints the parser http method
    puts "Method: " + @parser.http_method
    # prints the parser request path
    puts "Path: " + @parser.request_path
    puts "Here's all of @parser's methods #{(@parser.methods - Object.methods).sort}"
  end

  def parse
    # we feed it strings from sockets
    # append the HTTP GET string to the HTTP parser
    @parser << "GET / HTTP/1.1\r\n" 
    #this will break if you get the format wrong. why: teh first word #triggers a callback
    # this will also break IF there is no specific HTTP request
    # append the host to the HTTP Parser object
    # the path is the '/' 
    @parser << "Host: localhost:3000\r\n"
    # append the word accept to the HTTP Parser object
    @parser << "Accept: */*\r\n" # the accept in the string triggers a call back for method and path
    # append a new line that follwos HTTP conventions
    @parser << "\r\n"
  end
end

#get it running 
ParserDemo.new.parse
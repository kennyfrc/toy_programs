Process:

LAST UPDATE:
- CONFIG.RU study

!STUDY
  some theoretical unknowns:
  - what is a client socket?
  - what is a server socket?
  - what is a TCP server? what is its different vs UDP? 

TUBE.RB
  1.) Implement a simple Tube where a server socket accepts 1 HTTP GET request
  2.) After accepting the HTTP GET request, it reads the data
  3.) It then puts the data which includes what type of request, from which host, from which agent, and an indication if it's accepteds
  4.) Server socket should then send an HTTP response through the use of the #write method
  5.) You then close the socket

  * note: there are two sockets here -- a server socket which accepts the connection and the client socket to the remote connection (ie .to the browser or to curl)

TUBE2.RB
  1.) Refactor by making sure each method is tiny (Metz's rules)

PARSER_DEMO.RB
  1.) Test the parser by passing sample HTTP requests, host details, and acceptance details
  2.) Note that a callback method should be triggered given the HTTP request where it displays the Method and the Path

TUBE3.RB
  1.) Add teh parser (HTTP::Parser Object) in which will handle the incoming data from the client socket
  2.) The HTTP request will trigger callbacks
  3.) If the data > 1kb, then it will continue to iterate the parsing through an #until control expression until the data is fully parsed

  * break conditions *
  - if you remove the GET request in the HTTP request string, the parse will throw an " unable to read error "

CONFIG.RU
  # you will find this at the $root of your Rails and Sinatra Application (something like this)
  # we need to figure out how to #load the $rack application via config.ru
  # it's called .ru because it has access to special methods like run

  # in a normal rails app, there is a config.ru file that shows this:

  #===== config.ru =====
  # This file is used by Rack-based servers to start the application.
  # does require that special file located inside the framework that loads  the whole framework, boots your application, sets up some stuff
  # tell the Rack web server... run an X object as the rack application (run Rails.applicaiton => Rails is the rack applicaiton)
  # next step is to run config.ru in our server

  require ::File.expand_path('../config/environment', __FILE__)
  run Rails.application

  # when you request /sleep in a server, it will sleep/wait for 5 seconds


RACK_SIMPLE.RB
  1. rack should take in an information hash that has been parsed by the HTTP parser
  2. rack returns an array of tree items which is required by the rack-based server in order to produce an HTTP response

  with curl or through a browser, you will produce the following #HTTP_request:
  GET /users HTTP/1.1
  Host: localhost
  Connection: close

  then rack requires us to translate the above request to (via the HTTP parser):
  env = {
    "REQUEST_METHOD" => "GET",
    "PATH_INFO" => "/users",
    "HTTP_VERSION" => "1.1",
    "HTTP_HOST" => "localhost",
    "HTTP_CONNECTION" => "close"  
  }

  then for the repsonse part, rack requires us to return somethign like below (array of tree items)
  the web server will convert it to a valid http response
  [
    200,
    { 'Content-Length' => "34",
      'Content-Type' => "text/html"
    },
    [
      "<html>",
      " <h1>kthxbaie</h1>",
      "</html>"
    ]
  ]


TUBE3.RB
  1.) Upon message complete (which is triggered by a callback), print the GET, the PATH, the Headers
  1.a) Initialize an env hash which contains the #parsed HTTP request
  1.b) This triggers the send_response which calls the rack application...
  1.c) ...and sets the (now) array of trees into status, headers, body
  2.) and writes some stuff into the stocket
  3.) print a message from the rack application to the client socket

  * for it to run, the app needs to be initialized in both the server socket and teh client socket

  what we're doing is a server for hosting a rack application


So far:
- it does not support POST requests
- it does not support concurrency (which is the key differentiator for servers -> the concurrency model)


TUBE4.RB








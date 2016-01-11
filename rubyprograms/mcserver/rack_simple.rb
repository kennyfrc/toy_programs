class MyApp
  def call(env) # env = request info hash that we have parsed using our HTTP parser (so that's compliant to the format) then you pass it to call method
    # we then require the app returns an $array of 3 items:
    [
      200, # status code
      { 'Content/Type' => 'text/plain'}, # header
      ["you requested " + env['PATH_INFO']] # body 
    ]
  end
end

# with curl or through a browser, you will produce the following #HTTP_request:
# GET /users HTTP/1.1
# Host: localhost
# Connection: close

# then rack requires us to translate the above request to (via the HTTP parser):
# env = {
#   "REQUEST_METHOD" => "GET",
#   "PATH_INFO" => "/users",
#   "HTTP_VERSION" => "1.1",
#   "HTTP_HOST" => "localhost",
#   "HTTP_CONNECTION" => "close"  
# }

# then for the repsonse part, rack requires us to return somethign like below (array of tree items)
# the web server will convert it to a valid http response
# [
#   200,
#   { 'Content-Length' => "34",
#     'Content-Type' => "text/html"
#   },
#   [
#     "<html>",
#     " <h1>kthxbaie</h1>",
#     "</html>"
#   ]
# ]
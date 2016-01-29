var readline = require('readline');

var rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

rl.question(">>What's your name?  ", function(answer) {
   console.log("Hello " + answer);
   rl.close();
});
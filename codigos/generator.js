var fs = require('fs');
var ms = new Set();
var size = 1000000;

const output = fs.createWriteStream('./stdout.log');
const errorOutput = fs.createWriteStream('./stderr.log');
// custom simple logger
const logger = new console.Console(output, errorOutput);

logger.log(size);
logger.log(1);

while(ms.size < size) {
  ms.add((Math.floor(Math.random() * size + 1)));
}

ms.forEach(function(value) {
  logger.log(value);
});

logger.log("1 ");
logger.log(size);
logger.log("0 0");

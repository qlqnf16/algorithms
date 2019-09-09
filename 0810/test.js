const input = require('fs').readFileSync('/dev/stdin').toString().trim().split("\n");

for (let i = 1; i <= input[0]; i++) {
  console.log(i)
}
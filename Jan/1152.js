const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

rl.on('line', line => {
  countWords(line);
  rl.close();
})

const countWords = line => {
  let words = 0;
  let isWord = false;
  [...line].forEach(char => {
    if (!isWord) {
      if (char != ' ') {
        isWord = true;
        words++;
      }
    } else {
      if (char == ' ') {
        isWord = false;
      }
    }
  });
  console.log(words);
}
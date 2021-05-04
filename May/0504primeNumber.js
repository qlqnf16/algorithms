const primeNumber = [];
let count = 0;

function makeNumber(number, papers, idx, cnt, length) {
  if (cnt >= length) {
    const num = number.join("") * 1;
    if (primeNumber[num]) count++;
    return;
  }
  for (let i = idx; i < papers.length; i++) {
    number.push(papers[i]);
    makeNumber(number, papers, idx + 1, cnt + 1, length);
    number.pop();
  }
}

function makePrimeNumberTable(maxNum) {
  for (let i = 1; i <= maxNum; i++) {
    primeNumber.push(true);
  }
  primeNumber[0] = primeNumber[1] = false;
  for (let i = 2; i <= maxNum; i++) {
    if (!primeNumber[i]) continue;
    for (let j = 2; i * j <= maxNum; j++) {
      primeNumber[i * j] = false;
    }
  }
}

function solution(numbers) {
  makePrimeNumberTable(9999999);
  for (let i = 1; i <= numbers.length; i++) {
    makeNumber([], numbers, 0, 0, i);
  }
  return count;
}

console.log(solution("17"));

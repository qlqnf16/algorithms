function decToBin(decimal) {
  const binary = [];
  while (decimal > 0) {
    binary.push(decimal % 2);
    decimal = Math.floor(decimal / 2);
  }
  binary.reverse();
  return binary;
}

function binToDec(binary) {
  let num = 0;
  const _binary = Object.assign([...binary]);
  _binary.reverse();
  for (let i = 0, mul = 1; i < _binary.length; i++, mul *= 2) {
    const element = _binary[i];
    num += element * mul;
  }
  return num;
}

function makeNextNumber(binary) {
  const nextNumber = [1];
  let _binary = Object.assign([...binary]);
  for (let i = 0; i < _binary.length; i++) {
    if (_binary[i] === 1) {
      _binary[i] = 0;
      break;
    }
  }
  _binary.sort();
  _binary.forEach((e) => nextNumber.push(e));
  return nextNumber;
}

function solution(n) {
  const binary = decToBin(n);
  const nextNumber = makeNextNumber(binary);
  const answer = binToDec(nextNumber);
  return answer;
}

console.log(solution(78));

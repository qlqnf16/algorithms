function solution(n) {
  let answer = 0;
  const numLength = toString(n).length;
  let counter = 1;
  for (let i = 0; i < numLength; i++) {
    answer += Math.floor(((n % counter) * 10) / counter);
    counter *= 10;
  }

  return answer;
}

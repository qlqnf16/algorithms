function solution(n) {
  const maxNum = Math.floor((n * (n + 1)) / 2);
  const dirr = [1, 0, -1];
  const dirc = [0, 1, -1];
  let pyramid = [[]];
  let num = 1,
    r = 0,
    c = 0,
    d = 0;
  while (num <= maxNum) {
    console.log(r, c, num);
    if (
      (pyramid[r + dirr[d]] && pyramid[r + dirr[d]][c + dirc[d]]) ||
      (d === 0 && r === n - 1) ||
      (d === 1 && c === n - 1) ||
      (d === 2 && r === 0)
    ) {
      d = d + 1 === 3 ? 0 : d + 1;
    }
    if (!pyramid[r][c]) {
      pyramid[r][c] = num;
      num++;
    }
    r += dirr[d];
    c += dirc[d];
    if (!pyramid[r]) pyramid[r] = [];
  }
  const answer = [];
  for (let i = 0; i < n; i++) {
    for (let j = 0; j <= i; j++) {
      answer.push(pyramid[i][j]);
    }
  }
  return answer;
}

console.log(solution(4));

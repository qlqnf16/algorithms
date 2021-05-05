function getGcd(a, b) {
  return a % b === 0 ? b : getGcd(b, a % b);
}

function getDeletedSquares(w, h) {
  let sum = 0;
  for (let i = 1; i < w; i++) {
    const cw = w - i;
    const ch = Math.floor((h / w) * cw);
    sum += ch;
  }
  return w * h - sum * 2;
}

function solution(w, h) {
  const gcd = getGcd(w, h);
  const deletedSquares = getDeletedSquares(
    Math.floor(w / gcd),
    Math.floor(h / gcd)
  );
  return w * h - deletedSquares * gcd;
}

console.log(solution(8, 12));

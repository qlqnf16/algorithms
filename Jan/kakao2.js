function solution(m, v) {
  var answer = 0;
  const board = [m];
  let boLevel = 0;

  v.forEach(length => {
    for (let i = boLevel; i >= 0; i--) {
      if (board[i] < length) {
        if (i === boLevel) {
          board.push(m - length);
          boLevel++;
        } else {
          board[i + 1] -= length;
        }
        break;
      }
      if (i === 0) {
        board[i] -= length;
        break;
      }
    }
  });

  answer = boLevel + 1;
  return answer;
}

const m = 4;
const v = [3, 2, 3, 1];
console.log(solution(m, v));
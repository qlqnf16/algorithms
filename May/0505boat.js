function solution(people, limit) {
  let answer = 0;
  const _people = Object.assign([...people]);
  _people.sort((a, b) => a - b);

  let lp = 0;
  let rp = _people.length - 1;
  while (lp <= rp) {
    answer++;
    if (_people[lp] + _people[rp] <= limit) {
      lp++;
      rp--;
    } else {
      rp--;
    }
  }

  return answer;
}

const p = [20, 71, 30, 81];
console.log(solution(p, 100));

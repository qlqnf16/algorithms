function calcPeopleCnt(times, totalTime) {
  let count = 0;
  times.forEach(time => {
    count += Math.floor(totalTime / time);
  })
  return count;
}

function solution(n, times) {
  let start = 0;
  let end = n * Math.max(...times);
  let answer = end;

  while (start <= end) {
    const mid = Math.floor((start + end) / 2);
    const peopleCnt = calcPeopleCnt(times, mid);
    if (peopleCnt >= n) {
      end = mid - 1;
      if (answer >= mid) answer = mid;
    } else {
      start = mid + 1;
    }
  }

  return answer
}

console.log(solution(6, [7, 10]));
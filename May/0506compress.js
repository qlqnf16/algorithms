function compressString(s, n) {
  let dupCnt = 1;
  let prev = s.slice(0, n);
  let newString = "";
  for (let i = n; i <= s.length; i += n) {
    const cur = s.slice(i, i + n);
    if (cur === prev) dupCnt++;
    else {
      newString += dupCnt > 1 ? `${dupCnt}` : "";
      newString += prev;
      prev = cur;
      dupCnt = 1;
    }
  }
  if (prev.length <= s.length) {
    newString += prev;
  }
  return newString;
}

function solution(s) {
  let answer = s.length;
  for (let i = 1; i < s.length; i++) {
    const compressedString = compressString(s, i);
    answer = Math.min(answer, compressedString.length);
  }
  return answer;
}

console.log(solution("ababcdcdababcdcd"));

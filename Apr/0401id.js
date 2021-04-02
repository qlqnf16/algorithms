function solution(new_id) {
  var answer = new_id.toLowerCase()
    .replace(/[^a-z-_.0-9]/g, "")
    .replace(/(\.+)/g, '.')
    .replace(/\.$|^\./g, '');
  if (answer.length == 0) answer = 'a';
  if (answer.length > 15) {
    answer = answer.slice(0, 15).replace(/\.$/, "");
  }
  while (answer.length < 3) {
    answer += answer[answer.length - 1];
  }

  return answer;
}
const visit = [];
const graph = [];
const showCnt = [];
const levels = [];

function dfs(start, node, level) {
  visit[node] = start;
  levels[node] = level;
  let cardCnt, startCycle;
  const nextNode = graph[node];

  if (!nextNode) {
    showCnt[node] = 1;
    return [1, 0];
  }
  if (!visit[nextNode]) {
    [cardCnt, startCycle] = dfs(start, nextNode, level + 1);
    if (!startCycle) {
      showCnt[node] = cardCnt + 1;
      return [cardCnt + 1, startCycle];
    } else {
      showCnt[node] = level >= startCycle ? cardCnt : cardCnt + 1;
      return [showCnt[node], startCycle];
    }
  } else {
    if (visit[nextNode] == start) {
      showCnt[node] = level - levels[nextNode] + 1;
      return [showCnt[node], levels[nextNode]];
    }
    else {
      showCnt[node] = showCnt[nextNode] + 1;
      return [showCnt[node], 0]
    }
  }
}

function solution(next_student) {
  var answer = 0;
  const size = next_student.length + 1;

  for (let i = 0; i < size; i++) {
    visit[i] = 0;
    showCnt[i] = 0;
  }
  for (let i = 1; i < size; i++) {
    const element = next_student[i - 1];
    graph[i] = element;
  }

  for (let i = 1; i < size; i++) {
    if (!visit[i]) {
      dfs(i, i, 1);
    }
  }

  let maxShowCnt = 0;
  for (let i = 1; i < size; i++) {
    if (maxShowCnt <= showCnt[i]) {
      maxShowCnt = showCnt[i];
      answer = i;
    }
  }

  console.log(showCnt)
  console.log(levels)
  return answer;
}

const next_student = [5, 9, 13, 1, 0, 0, 11, 1, 7, 12, 9, 9, 2]
console.log(solution(next_student));
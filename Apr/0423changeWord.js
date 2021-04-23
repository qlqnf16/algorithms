class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.head = null;
    this.rear = null;
    this.length = 0;
  }

  add(data) {
    const node = new Node(data);
    if (!this.head) {
      this.head = node;
    } else {
      this.rear.next = node;
    }
    this.rear = node;
    this.length++;
  }

  poll() {
    if (!this.head) {
      return false;
    }
    const data = this.head.data;
    this.head = this.head.next;
    this.length--;

    return data;
  }

  front() {
    return this.head && this.head.data;
  }
}

function isChangable(word, comp) {
  let diffCnt = 0;
  for (let i = 0; i < word.length; i++) {
    const w = word[i];
    const c = comp[i];
    if (w !== c) {
      diffCnt++;
      if (diffCnt >= 2) return false;
    }
  }
  return true;
}

function bfs(begin, target, words) {
  const q = new Queue();
  q.add([begin, 0]);

  while (q.length) {
    const [current, count] = q.poll();
    if (current === target) return count;

    for (let i = 0; i < words.length; i++) {
      if (words[i] === '') continue;
      if (isChangable(current, words[i])) {
        q.add([words[i], count + 1]);
        words[i] = '';
      }
    }
  }

  return 0;
}

function solution(begin, target, words) {
  const answer = bfs(begin, target, words);
  return answer;
}

console.log(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]));
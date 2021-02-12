function solution(n, record) {
  var answer = [];
  const servers = [];
  for (let i = 0; i < n; i++) {
    servers[i] = [];
  }

  record.forEach(element => {
    const [N, nickName] = element.split(' ');
    const idx = parseInt(N) - 1;
    if (!servers[idx].find(ele => ele === nickName)) {
      if (servers[idx].length === 5) {
        servers[idx].shift();
      }
      servers[idx].push(nickName);
    }
  });

  servers.forEach(server => {
    if (server.length) {
      server.forEach(user => answer.push(user));
    }
  })

  return answer;
}

const n = 1;
const record = ["1 fracta", "1 sina", "1 hana", "1 robel", "1 abc", "1 sina", "1 lynn"];
console.log(solution(n, record));

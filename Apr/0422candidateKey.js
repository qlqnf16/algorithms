let gRelation = [];
const combis = [];

function checkUnique(combi) {
  for (let i = 0; i < gRelation.length; i++) {
    let base = '';
    combi.forEach(idx => base += `${gRelation[i][idx]}/`);
    for (let j = i + 1; j < gRelation.length; j++) {
      let comp = '';
      combi.forEach(idx => comp += `${gRelation[j][idx]}/`)
      if (base === comp) return false;
    }
  }
  return true;
}

function makeCombi(idx, combi, n, r, count) {
  if (count >= r) {
    if (checkUnique(combi)) {
      combis.push(Object.assign([], combi));
    }
    return;
  }
  for (let i = idx; i < n; i++) {
    combi.push(i);
    makeCombi(i + 1, combi, n, r, count + 1);
    combi.pop();
  }
}

function makeCandidateKey() {
  let keyCnt = combis.length;

  for (let i = 0; i < combis.length; i++) {
    const baseCombi = combis[i];
    if (baseCombi === '') continue;
    for (let j = i + 1; j < combis.length; j++) {
      const compCombi = combis[j];
      if (baseCombi.every(idx => compCombi.includes(idx))) {
        combis[j] = ''
        keyCnt--;
      }
    }
  }

  return keyCnt;
}

function solution(relation) {
  var answer = 0;
  gRelation = relation;
  const columns = relation[0].length;
  for (let i = 1; i <= columns; i++) {
    makeCombi(0, [], columns, i, 0);
  }
  // console.log(combis);
  answer = makeCandidateKey();
  // console.log(combis);
  return answer;
}

const r = [["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"], ["400", "con", "computer", "4"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]];
console.log(solution(r));
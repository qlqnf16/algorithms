let infoDict = {}

function makeCases(infoArr, idx, newStr) {
  if (idx == 4) {
    const score = Number(infoArr[idx]);
    if (infoDict[newStr]) {
      infoDict[newStr].push(score)
    } else {
      infoDict[newStr] = [score];
    }
    return;
  }

  makeCases(infoArr, idx + 1, newStr + infoArr[idx]);
  makeCases(infoArr, idx + 1, newStr + '-');
}

function sortDict() {
  for (const key in infoDict) {
    infoDict[key].sort((a, b) => a - b);
  }
}

function lowerBound(arr, target) {
  let s = 0;
  let e = arr.length - 1;
  let m = e;

  if (arr[e] < target) return -1;

  while (s < e) {
    m = parseInt((s + e) / 2);
    if (arr[m] < target) {
      s = m + 1;
    } else {
      e = m;
    }
  }

  return s;
}

function getQueryResult(query) {
  const [condition, score] = query.replace(/ and /g, '').split(' ');
  if (infoDict[condition]) {
    const lb = lowerBound(infoDict[condition], Number(score));
    if (lb == -1) return 0;
    return infoDict[condition].length - lb;
  } else {
    return 0;
  }
}

function solution(info, query) {
  var answer = [];

  info.forEach(element => {
    makeCases(element.split(' '), 0, '');
  })
  sortDict();
  query.forEach(element => {
    answer.push(getQueryResult(element));
  })

  return answer;
}

function isRightString(p) {
  const stack = [];
  for (let i = 0; i < p.length; i++) {
    const e = p.charAt(i);
    if (e === "(") stack.push(e);
    else {
      const tmp = stack.pop();
      if (!tmp || tmp === ")") return false;
    }
  }
  return true;
}

function cutString(p) {
  let equalNum = p.charAt(0) === "(" ? 1 : -1;
  let u = "",
    v = "";
  for (let i = 1; i < p.length; i++) {
    const e = p.charAt(i);
    equalNum += e === "(" ? 1 : -1;
    if (equalNum === 0) {
      u = p.slice(0, i + 1);
      v = p.slice(i + 1);
      break;
    }
  }
  if (!u) return [p, ""];
  else return [u, v];
}

function makeNewU(u) {
  let newU = "";
  for (let i = 1; i < u.length - 1; i++) {
    newU += u[i] === "(" ? ")" : "(";
  }
  return newU;
}

function makeRightString(p) {
  if (!p) return "";
  const [u, v] = cutString(p);
  if (isRightString(u)) {
    return u + makeRightString(v);
  } else {
    return "(" + makeRightString(v) + ")" + makeNewU(u);
  }
}

function solution(p) {
  if (isRightString(p)) return p;
  const answer = makeRightString(p);
  return answer;
}

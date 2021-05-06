function rotateKey(key, n) {
  let _key = [];
  for (let r = 0; r < n; r++) {
    _key[r] = [];
    for (let c = 0; c < n; c++) {
      _key[r][c] = key[c][n - 1 - r];
    }
  }
  return _key;
}

function checkLock(lock, n, m) {
  for (let i = n - 1; i < m + n - 1; i++) {
    for (let j = n - 1; j < m + n - 1; j++) {
      if (lock[i][j] !== 1) return false;
    }
  }
  return true;
}

function isKeyFit(key, lock, m, n) {
  for (let i = 0; i < n + m - 1; i++) {
    for (let j = 0; j < n + m - 1; j++) {
      let _lock = lock.map((l) => l.slice());
      for (let r = 0; r < n; r++) {
        for (let c = 0; c < n; c++) {
          _lock[r + i][c + j] += key[r][c];
        }
      }
      if (checkLock(_lock, n, m)) return true;
    }
  }
  return false;
}

function makePadding(lock, m, n) {
  let paddedLock = [];
  const newSize = m + n * 2 - 2;
  for (let i = 0; i < newSize; i++) {
    paddedLock[i] = [];
    for (let j = 0; j < newSize; j++) {
      paddedLock[i][j] = 1;
    }
  }
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < m; j++) {
      paddedLock[i + n - 1][j + n - 1] = lock[i][j];
    }
  }
  return paddedLock;
}

function solution(key, lock) {
  const n = key[0].length;
  const m = lock[0].length;
  let _key = key.map((k) => k.slice());

  const paddedLock = makePadding(lock, m, n);
  for (let i = 0; i < 4; i++) {
    if (isKeyFit(_key, paddedLock, m, n)) return true;
    _key = rotateKey(_key, n);
  }

  return false;
}

const k = [
  [0, 0, 0],
  [1, 0, 0],
  [0, 1, 1],
];
const l = [
  [1, 0],
  [0, 1],
];
console.log(solution(k, l));

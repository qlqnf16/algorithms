let _prices;
let _minSum = Number.MAX_VALUE;

function selectPrice(idx, cnt, selection, n, d, k) {
  if (cnt >= k) {
    const selectedPrices = [];
    selection.forEach(s => selectedPrices.push(_prices[s]));
    if (selectedPrices[k - 1] - selectedPrices[0] <= d) {
      const sum = selectedPrices.reduce((prev, cur) => prev + cur);
      _minSum = Math.min(_minSum, sum);
    }
    return;
  }

  for (let i = idx; i < n; i++) {
    selection.push(i);
    selectPrice(i + 1, cnt + 1, selection, n, d, k);
    selection.pop();
  }
}

function solution(prices, d, k) {
  let sum, total;
  const n = prices.length;
  _prices = Object.assign([], prices);
  _prices.sort();

  // 1.
  const endIdx = n - 1;
  if (_prices[endIdx] - _prices[0] <= d) {
    sum = _prices.reduce((prev, cur) => prev + cur);
    total = n;
  }
  // 2.
  else if (_prices[endIdx - 1] - _prices[1] <= d) {
    sum = _prices.reduce((prev, cur) => prev + cur) - (_prices[endIdx] + _prices[0]);
    total = n - 2;
  }
  else {
    // 3.
    selectPrice(0, 0, [], n, d, k);
    if (_minSum < Number.MAX_VALUE) {
      sum = _minSum;
      total = k;
    } else {
      // 4.
      const midIdx = Math.floor((n - 1) / 2);
      sum = _prices[midIdx];
      total = 1;
    }
  }

  const answer = Math.floor(sum / total);
  return answer;
}
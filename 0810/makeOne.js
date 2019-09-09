const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

rl.on('line', line => {
  makeOne(line * 1)
  rl.close()
})

const makeOne = (num) => {
  const dp = new Array(num + 1)
  dp[0] = 0; dp[1] = 0; dp[2] = 1; dp[3] = 1;

  for (let i = 4; i <= num; i++) {
    if (i % 3 === 0 && i % 2 === 0) dp[i] = Math.min(dp[i / 3], dp[i / 2], dp[i - 1]) + 1
    else if (i % 3 === 0) dp[i] = Math.min(dp[i / 3], dp[i - 1]) + 1
    else if (i % 2 === 0) dp[i] = Math.min(dp[i / 2], dp[i - 1]) + 1
    else dp[i] = dp[i - 1] + 1
  }

  console.log(dp[num])
}
const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

rl.on('line', line => {
  // function goes here
  countNums(line * 1)
  rl.close()
})

const pages = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

const countNums = num => {
  if (num === 0)
    return [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
  else {
    const tempArr = countNums(num - 1)
    const numArr = num.toString().split('')
    numArr.forEach(ele => {
      tempArr[ele * 1] += 1
    })
    return tempArr
  }
}
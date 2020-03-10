const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

const input = []
rl.on('line', line => {
  input.push(line)
  if (input.length === 4) rl.close()
})
rl.on('close', _ => {
  console.log(N)
  process.exit()
})
const [N, M] = [input[0] * 1, input[2] * 1]
const numsArray = input[1].split(' ').map(ele => ele * 1)
const searchNums = input[3].split(' ').map(ele => ele * 1)
numsArray.sort((a, b) => a - b)

const bs = () => {

}
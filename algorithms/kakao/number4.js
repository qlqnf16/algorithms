words = ["frog", "smog", "fame"]
queries = ["????"]
const checkValidQuery = (query) => {
  if (query.match(/\W/g) === null)
    return false
  else
    return true
}

const getLengthObject = (words) => {
  const obj = {}
  for (let word of words) {
    if (obj[word.length])
      obj[word.length].push(word)
    else
      obj[word.length] = [word]
  }
  return obj
}

const countWords = (query, wordObj) => {
  const wordLen = query.length
  let regex

  if (query[0] === '?') {
    regex = query[wordLen - 1] === '?' ? /\w*/g : new RegExp('\\w*' + query.slice((/\w/).exec(query).index) + '$', 'g')
  } else {
    regex = new RegExp(query.slice(0, (/\W/).exec(query).index) + '\\w*', 'g')
  }

  let count = 0
  const searchTarget = wordObj[JSON.stringify(wordLen)]
  if (searchTarget) {
    searchTarget.forEach(word => {
      const matched = word.match(regex)
      if (matched) count++
    })
  }

  return count
}

function solution(words, queries) {
  var answer = [];
  const wordObj = getLengthObject(words)
  queries.forEach(query => {
    if (checkValidQuery(query)) {
      answer.push(countWords(query, wordObj))
    }
  })

  return answer;
}
console.log(solution(words, queries))
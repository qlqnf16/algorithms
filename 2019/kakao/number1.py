inputList = ['abbbcd']

def getShortened(sentence, repeat):
  finalStr = ''
  i = 0
  count = 1
  while i <= len(sentence)-1:
    tempStr = sentence[i:i+repeat]
    if sentence[i: i + repeat] == sentence[i + repeat : i + repeat * 2]:
      count += 1
      i += repeat
    else:
      if count == 1:
        if len(sentence[i + repeat : i + repeat * 2]) < repeat:
          finalStr += tempStr + sentence[i + repeat : i + repeat * 2]
          return finalStr
        finalStr += tempStr[0]
        i += 1
      else:
        finalStr += str(count) + tempStr
        i += repeat
      count = 1
    
  return finalStr

def checkRepeat(sentence):
  maxLen = len(sentence) // 2
  finalMin = 1000

  while maxLen >= 1:
    if sentence[:maxLen] == sentence[maxLen:(maxLen*2)] or maxLen == 1:
      tempMin = len(getShortened(sentence, maxLen))
      if finalMin > tempMin:
        finalMin = tempMin
    maxLen -= 1

  return finalMin

def solution(s):
  repeat = checkRepeat(s)
  return repeat

for input in inputList:
  print(solution(input))
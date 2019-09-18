N = int(input())
result = ['0'] * 100
isFinished = False

def checkGoodSeq(seq, x):
  for i in range(1, x//2+1+1):
    end = x + 1
    if ''.join(seq[end-i:end]) == ''.join(seq[end-i-i:end-i]):
      return False
  return True

def getResult(x):
  global isFinished
  if isFinished:
    return

  if x >= N:
    print(''.join(result[0:x]))
    isFinished = True
    return
  
  for i in range(1, 4):
    result[x] = str(i)
    possible = checkGoodSeq(result, x)
    if possible:
      getResult(x+1)

getResult(0)
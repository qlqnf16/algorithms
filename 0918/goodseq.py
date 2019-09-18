from itertools import permutations

N = int(input())

# 모든경우: 1111... ~ 3333... 3^N개
goodSeqArr = ['1', '12', '121', '1213', '12131', '121312', '1213121', '12131231']
items = ['1','2','3']

# 나쁜 수열인지 체크
def checkGoodSeq(seq):
  length = len(seq)
  for i in range(1, length//2+1):
    end = length
    if seq[end-i:end] == seq[end-i-i:end-i]:
      return False
  return True
  
def replaceTwo(goodSeqArr, size):
  for i in range(1, 4):
    for j in range(1, 4):
      newSeq = goodSeqArr[size-2] + str(i) + str(j)
      if checkGoodSeq(newSeq):
        goodSeqArr.append(newSeq)
        return True
  return False

def replaceThree(goodSeqArr, size):
  for i in range(1, 4):
    for j in range(1, 4):
      for k in range(1, 4):
        newSeq = goodSeqArr[size-3] + str(i) + str(j) + str(k)
        if checkGoodSeq(newSeq):
          added = True
          goodSeqArr.append(newSeq)
          return

if N <= len(goodSeqArr):
  print(goodSeqArr[N-1])
else:
  size = 0
  while size < N-1:
    size = len(goodSeqArr)
    added = False
    for i in range(1, 4):
      newSeq = goodSeqArr[size-1] + str(i)
      if checkGoodSeq(newSeq):
        goodSeqArr.append(newSeq)
        added = True
        break
    if not added:
      added = replaceTwo(goodSeqArr, size)
    if not added:
      replaceThree(goodSeqArr, size)

  print(goodSeqArr[-1])
  print(len(goodSeqArr[-1]))
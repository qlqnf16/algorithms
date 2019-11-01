import queue

t = int(input())

# 소수 목록 미리 저장
primeNums = [True] * 10000
for i in range(2, 10000):
  if primeNums[i]:
    n = 2
    while i*n < 10000:
      nums[i*n] = False
      n += 1

def getNext(start, end):
  q = queue.Queue()
  visit = [False] * 10000
  count = [0] * 10000
  q.put(start)
  visit[start] = True

  while not q.empty():
    num = q.get()

    for i in range(4):
      # 각 자리수에 대해 변형
      n = int(str(num)[i])
      for j in range(0, 10):
        nextNum = num + (j-n)*(10**(3-i)) 
        if nextNum > 999 and not visit[nextNum]:
          visit[nextNum] = True
          if primeNums[nextNum]:
            q.put(nextNum)
            count[nextNum] = count[num] + 1
        if nextNum == end:
          return count[num] + 1
  
  return "impossible"
        
for _ in range(t):
  start, end = map(int, input().split())
  if start == end:
    print(0)
  else:
    print(getNext(start, end))
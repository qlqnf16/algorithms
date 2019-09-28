# [[1, 0, 3], [2, 1, 3], [3, 3, 2], [4, 9, 1], [5, 10, 2]]
# [인풋 순서, 몇초에 인풋이 들어왔는지, 몇페이지 인쇄해야되는지]

queue = [[1,10,10],[2,15,3],[3,15,1],[4,16,1],[5,17,5]]
time = [0]*100000
result = []

for order in queue:
  if time[order[1]] != 0:
    time[order[1]] = order
  else:
    time[order[1]].append

# 대기열 확인
# 하나면 하나 시작
# 둘 이상이면 우선순위 비교해서 그거부터 시작
# n 초 지난 후 반복
# 대기열 비면 return

def printInQueue(e):
  if len(result) == len(queue):
    return
  tempQueue = []
  for i in range(0, e):
    if time[i] != 0 and len(time[i]) == 3:
      tempQueue.append(time[i])
  if e <= 100:
    print(f'{e} {result}')
  if len(tempQueue) == 0:
    pages = 1
  elif len(tempQueue) == 1:
    pages = tempQueue[0][2]
    queue[tempQueue[0][0] - 1].append(1)
    result.append(tempQueue[0][0])
  else:
    minp = 987987987
    mini = 0
    for order in tempQueue:
      if order[2] < minp:
        minp = order[2]
        mini = order[0] - 1
    pages = minp
    queue[mini].append(1)
    result.append(mini+1)
  printInQueue(e+pages)

printInQueue(1)
print(result)
  
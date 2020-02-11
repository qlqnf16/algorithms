import queue

n = int(input())
houses = []*n
for _ in range(n):
  houses.append(list(map(int, list(input()))))

visit = [[False for j in range(n)] for i in range(n)]

def BFS(x, y):
  global n
  global visit
  q = queue.Queue()
  q.put([x,y])
  direction = [[1,0,0,-1],[0,1,-1,0]]
  count = 0
  
  while q.qsize() > 0:
    currentX, currentY = q.get()

    for i in range(0, 4):
      nextX = currentX + direction[0][i]
      nextY = currentY + direction[1][i]

      if 0<= nextX <n and 0 <= nextY < n:
        if houses[nextX][nextY] == 1 and visit[nextX][nextY] == False:
          q.put([nextX, nextY])
          visit[nextX][nextY] = True
          count += 1
  
  if count == 0:
    return 1
  else:
    return count
    
count = 0
houseCount = []

for i in range(n):
  for j in range(n):
    if houses[i][j] == 1 and visit[i][j] == False:
      count += 1
      houseCount.append(BFS(i, j))

houseCount.sort()

print(count)
print("\n".join(str(i) for i in houseCount))
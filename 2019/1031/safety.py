import queue

n = int(input())
zone = []
maxarea = 0

for _ in range(n):
  zone.append(list(map(int, input().split())))

direction = [[0,0,1,-1],[1,-1,0,0]]

def BFS(r, c, height):
  global visit
  exist = False

  q = queue.Queue()
  q.put([r,c])
  visit[r][c] = True
  while not q.empty():
    x, y = q.get()
    
    for i in range(4):
      nextX = x + direction[0][i]
      nextY = y + direction[1][i]
      if 0 <= nextX < n and 0 <= nextY < n and not visit[nextX][nextY]:
        if zone[nextX][nextY] > height:
          visit[nextX][nextY] = True
          q.put([nextX, nextY])

for i in range(1, 101):
  visit = [[False for _ in range(n)] for k in range(n)]
  tempMax = 0
  for r in range(n):
    for c in range(n):
      if zone[r][c] > i and not visit[r][c]:
        tempMax += 1
        BFS(r, c, i)
  if tempMax > maxarea:
    maxarea = tempMax

print(maxarea)
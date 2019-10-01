import queue

n, m = map(int, input().split())
maze = [] * n
for _ in range(n):
  maze.append(list(map(int, input().split())))

visited = [[False for i in range(m)] for j in range(n)]
count = [[0 for i in range(m)] for j in range(n)]
q = queue.Queue()
direction = [[1,0,-1,0],[0,1,0,-1]]
disMin = 987987987

q.put([n-1, 0])
visited[n-1][0] = True

while q.qsize() > 0:
  x, y = q.get()
  
  for i in range(0, 4):
    nextX = direction[0][i] + x
    nextY = direction[1][i] + y

    if 0 <= nextX < n and 0 <= nextY < m:
      if visited[nextX][nextY] == False:
        visited[nextX][nextY] = True
        count[nextX][nextY] = count[x][y] + 1
        if maze[nextX][nextY] == 0:
          q.put([nextX, nextY])

visited = [[False for i in range(m)] for j in range(n)]
countFromTop = [[0 for i in range(m)] for j in range(n)]
disMin = 987987987

q.put([0, m-1])
visited[0][m-1] = True

while q.qsize() > 0:
  x, y = q.get()
  
  for i in range(0, 4):
    nextX = direction[0][i] + x
    nextY = direction[1][i] + y

    if 0 <= nextX < n and 0 <= nextY < m:
      if visited[nextX][nextY] == False:
        visited[nextX][nextY] = True
        countFromTop[nextX][nextY] = countFromTop[x][y] + 1
        if maze[nextX][nextY] == 0:
          q.put([nextX, nextY])
        elif count[nextX][nextY] > 0:
          tempMin = countFromTop[nextX][nextY] + count[nextX][nextY]
          if tempMin < disMin:
            disMin = tempMin
            
print(disMin)

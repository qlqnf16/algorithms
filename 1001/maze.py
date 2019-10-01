import queue

n, m = map(int, input().split())
maze = [] * n
for _ in range(n):
  maze.append(list(map(int, input().split())))

visited = [[False for i in range(m)] for j in range(n)]
count = [[0 for i in range(m)] for j in range(n)]
q = queue.Queue()
q.put([n-1, 0])
visited[n-1][0] = True
direction = [[1,0,-1,0],[0,1,0,-1]]

while q.qsize() > 0:
  x, y = q.get()
  
  for i in range(0, 4):
    nextX = direction[0][i] + x
    nextY = direction[1][i] + y

    if 0 <= nextX < n and 0 <= nextY < m:
      if maze[nextX][nextY] == 0 and visited[nextX][nextY] == False:
        visited[nextX][nextY] = True
        count[nextX][nextY] = count[x][y] + 1
        q.put([nextX, nextY])

print(count[0][m-1])

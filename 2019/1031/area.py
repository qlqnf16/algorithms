import queue

m, n, k = map(int, input().split())
area = [[0 for i in range(n)] for j in range(m)]

for _ in range(k):
  lr, lc, rr, rc = map(int, input().split())
  for i in range(m-rc, m-lc):
    for j in range(lr, rr):
      area[i][j] = 1

visit = [[False for r in range(n)] for c in range(m)]
direction = [[0,0,1,-1],[1,-1,0,0]]

def BFS(r, c):
  q = queue.Queue()
  q.put([r, c])
  visit[r][c] = True
  count = 1

  while not q.empty():
    x, y = q.get()
    
    for i in range(4):
      nx = x + direction[0][i]
      ny = y + direction[1][i]
      if 0 <= nx < m and 0 <= ny < n and not visit[nx][ny] and area[nx][ny] == 0:
        q.put([nx, ny])
        visit[nx][ny] = True
        count += 1
  
  return count

countList = []
for i in range(m):
  for j in range(n):
    if area[i][j] == 0 and not visit[i][j]:
      countList.append(BFS(i, j))

countList.sort()
print(len(countList))
print(" ".join(str(x) for x in countList))
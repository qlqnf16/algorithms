import queue

R, C = map(int, input().split())
maze = []
for _ in range(R):
  maze.append(list(map(int, list(input()))))


direction = [[0,0,1,-1],[1,-1,0,0]]
visit = [[False for c in range(C)] for r in range(R)]
route = [[1 for c in range(C)] for r in range(R)]

q = queue.Queue()
q.put([0,0])

while not q.empty():
  x, y = q.get()
  for i in range(4):
    nextX = x + direction[0][i]
    nextY = y + direction[1][i]

    if 0 <= nextX < R and 0 <= nextY < C and maze[nextX][nextY] == 1 and not visit[nextX][nextY]:
      q.put([nextX, nextY])
      visit[nextX][nextY] = True
      route[nextX][nextY] = route[x][y] + 1

print(route[R-1][C-1])
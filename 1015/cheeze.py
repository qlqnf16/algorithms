import queue

h, w = map(int, input().split())
plate = []
cheeze = 0

for _ in range(h):
  line = list(map(int, input().split()))
  plate.append(line)
  for i in line:
    if i == 1:
      cheeze += 1

q = queue.Queue()
direction = [[0,0,-1,1], [1,-1,0,0]]
startX, startY = 0, 0
air = 0
count = 0
changed = True
prevCheeze = 0

while cheeze > 0:
  prevCheeze = cheeze
  visited = [[False for _ in range(w)] for _ in range(h)]
  q.put([0, 0])
  visited[0][0] = True

  while q.qsize()>0:
    x, y = q.get()

    for i in range(4):
      nextX = x + direction[0][i]
      nextY = y + direction[1][i]

      if 0 <= nextX < h and 0 <= nextY < w:
        if plate[nextX][nextY] == 0 and not visited[nextX][nextY]:
          q.put([nextX, nextY])
          visited[nextX][nextY] = True
        elif plate[nextX][nextY] == 1:
          plate[nextX][nextY] = -1
          cheeze -= 1      

  for i in range(h):
    for j in range(w):
      if plate[i][j] == -1:
        plate[i][j] = 0
        
  count += 1

print(count)
print(prevCheeze)


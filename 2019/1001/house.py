n = int(input())
houses = []
for _ in range(n):
  houses.append(list(map(int, list(input()))))

visited = [[False for i in range(n)] for j in range(n)]
direction = [[1,0,0,-1],[0,1,-1,0]]
count = 0
houseCount = []

def DFS(x, y, index):
  visited[x][y] = True
  if houses[x][y] == 1:
    houseCount[index] += 1

    for i in range(0,4):
      nextX = x + direction[0][i]
      nextY = y + direction[1][i]

      if 0 <= nextX < n and 0 <= nextY < n:
        if visited[nextX][nextY] == False:
          DFS(nextX, nextY, index)
  
for i in range(n):
  for j in range(n):
    if houses[i][j] == 1 and visited[i][j] == False:
      count += 1
      houseCount.append(0)
      DFS(i, j, len(houseCount)-1)

houseCount.sort()

print(count)
print("\n".join(str(i) for i in houseCount))
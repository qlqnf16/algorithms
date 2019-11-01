# 문제풀이 수정 (bfs => dfs)

R, C = map(int, input().split())
table = []

for _ in range(R):
  table.append(list(input()))

direction = [[0,0,1,-1],[1,-1,0,0]]
visit = [[False for c in range(C)] for r in range(R)]
letterCheck = [False for l in range(27)]
result = []
myMax = 1

def dfs(r, c, temp):
  result.append(table[r][c])
  visit[r][c] = True
  letterCheck[ord(table[r][c])-65] = True
  move = False
  global myMax

  for i in range(4):
    nr = direction[0][i] + r
    nc = direction[1][i] + c
    if 0 <= nr < R and 0 <= nc < C and not visit[nr][nc]:
      if not letterCheck[ord(table[nr][nc])-65]:
        dfs(nr, nc, temp+1)
        letterCheck[ord(table[nr][nc])-65] = False
        visit[nr][nc] = False
        if temp+1 > myMax:
          myMax = temp+1

dfs(0,0,1)
print(myMax)
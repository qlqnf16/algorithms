import queue

R, C = map(int, input().split())
table = []

for _ in range(R):
  table.append(list(input()))

def toNum(r, c):
  return ord(table[r][c])-65

direction = [[0,0,1,-1],[1,-1,0,0]]
q = queue.Queue()
visit = [[False for c in range(C)] for r in range(R)]
letterCheck = [False for l in range(27)]
q.put([0,0])
visit[0][0] = True
letterCheck[toNum(0,0)] = True
count = 0

while not q.empty():
  r, c = q.get()
  count += 1

  for i in range(4):
    nr = direction[0][i] + r
    nc = direction[1][i] + c
    if 0 <= nr < R and 0 <= nc < C and not visit[nr][nc]:
      if not letterCheck[toNum(nr,nc)]:
        q.put([nr, nc])
        visit[nr][nc] = True
        letterCheck[toNum(nr,nc)] = True

print(count)
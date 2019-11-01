n = int(input())
check = [[False for c in range(n)] for r in range(n)]
answer = 0

def dfs(row):
  global answer

  if row == n:
    answer += 1
  else:
    for c in range(n):
      column[c] = row
      if checkPossible(row+1):
        # column[c] = row+1
        dfs(row+1)
    # column[col] = -1

def checkPossible(c):
  for i in range(n):
    if column[i] == column[c] or column[i] - column[c] == i-c or column[c] - column[i] == c-1:
      print(column[i], column[c])
      return False
  return True

for i in range(n):
  column = [-1]*n
  column[i] = 0
  dfs(i)
  # print(column)

print(answer)
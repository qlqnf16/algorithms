n, m = map(int, input().split())
coniX, coniY = map(int, input().split())

def wayToConi(x, y):
  dp = [ [ 0 for i in range(x+1) ] for j in range(y+1) ]
  for i in range(x+1):
    dp[y][i] = 1
  for i in range(y+1):
    dp[i][0] = 1
  
  for i in range(y-1, -1, -1):
    for j in range(1, x+1):
      dp[i][j] = dp[i][j-1] + dp[i+1][j]

  # 좌표평면 확인
  # for i in range(y+1):
  #   print(dp[i])

  return dp[0][x]

if coniX > n or coniY > m or coniX < 0 or coniY < 0:
  print('fail')
else:
  print(coniX + coniY)
  print(wayToConi(coniX, coniY))
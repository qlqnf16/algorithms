N, M = map(int, input().split())
data = []
for _ in range(N):
  data.append(list(map(int, input().split())))

dp = [[ 0 for i in range(M)] for j in range(N)]
dp[0][0] = data[0][0]
for i in range(1, M):
  dp[0][i] = data[0][i] + dp[0][i-1]
for i in range(1, N):
  dp[i][0] = data[i][0] + dp[i-1][0]

for i in range(1, N):
  for j in range(1, M):
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + data[i][j]

print(dp[N-1][M-1])
str1 = input()
str2 = input()
n = len(str1)
m = len(str2)
dp = [[0 for i in range(n)] for j in range(m)]
if str1[0] != str2[0]:
  dp[0][0] = 0
else:
  dp[0][0] = 1

for i in range(1,n):
  if dp[0][i-1] == 1 or str1[i] == str2[0]:
    dp[0][i] = 1
for i in range(m):
  if dp[i-1][0] == 1 or str1[0] == str2[i]:
    dp[i][0] = 1

for i in range(1, m):
  for j in range(1, n):
    if str1[j] == str2[i]:
      dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j-1])
    else:
      dp[i][j] = max(dp[i][j-1], dp[i-1][j])

maxSame = dp[m-1][n-1]
print(n-maxSame + m-maxSame)
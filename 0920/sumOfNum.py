N = int(input())
dp = [0]*(N+1)

for i in range(1, N+1):
  iMin = 999999999
  n = 1

  while n*n <= i:
    temp = 1 + dp[i - n*n]
    if temp < iMin:
      iMin = temp
    n += 1
  
  dp[i] = iMin

print(dp[N])
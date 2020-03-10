import sys

n = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))

dp = [data[0]]
for i in range(1, n):
  dp.append(max(data[i], data[i]+dp[i-1]))

print(max(dp))
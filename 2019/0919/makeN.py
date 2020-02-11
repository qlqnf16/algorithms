n = int(input())
dp = [0,1,2,4]
mod = 1000007

def makeN(n):
  mySum = ((dp[n-1]%mod)+(dp[n-2]%mod)+(dp[n-3]%mod))%mod
  dp.append(mySum)

for i in range(4, n+1):
  makeN(i)

print(dp[n])
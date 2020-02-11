string = input()
length = len(string)

dp = [ [ 0 for i in range(length) ] for j in range(length) ]

for i in range(length-1):
  if string[i] != string[i+1]:
    dp[i+1][i] = 1
  else:
    dp[i+1][i] = 0

for i in range(1, length):
  for j in range(0, length-i):
    s, e = j, j+i
    if string[s] == string[e]:
      dp[s][e] = dp[s+1][e-1]
    else:
      dp[s][e] = min(dp[s][e-1], dp[s+1][e]) + 1

print(dp[0][length-1])
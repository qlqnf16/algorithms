string = input()
l = len(string)

isPalindrome = [ [ 0 for i in range(l) ] for j in range(l) ]
dp = [0]*l
dp[0] = 1

for i in range(l):
  isPalindrome[i][i] = 1

for i in range(l-1):
  if string[i] == string[i+1]:
    isPalindrome[i][i+1] = 1

for i in range(1, l):
  for j in range(0, l-i):
    s, e = j, j+i
    if isPalindrome[s+1][e-1] and string[s] == string[e]: 
      isPalindrome[s][e] = 1

for i in range(0, l):
  for j in range(0, i+1):
    if isPalindrome[j][i] and ((not dp[i]) or dp[i] > dp[j-1]+1):
      dp[i] = dp[j-1] + 1

print(dp[l-1])
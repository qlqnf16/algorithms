T = int(input())
direction = [[0,1], [0,-1], [1,0], [-1,0]]

def dfs(r, c, cnt, num):
  global nums
  num = num + table[r][c]
  if cnt >= 7:
    if num not in nums:
      nums.append(num)
    return

  for i in range(4):
    nextR = r + direction[i][0]
    nextC = c + direction[i][1]
    if 0 <=nextR< 4 and 0 <= nextC < 4:
      dfs(r+direction[i][0], c+direction[i][1], cnt+1, num)

for case in range(1, T+1):
  table = []
  nums = []
  for _ in range(4):
    table.append(list(input().split()))
  for i in range(4):
    for j in range(4):
      tempNum = dfs(i, j, 1, "")

  print(f"#{case} {len(nums)}")
      
    

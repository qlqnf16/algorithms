import sys

n = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))

def getSum(start, end):
  if start >= end:
    return data[start]
  
  mid = start + (end-start)//2
  left = getSum(start, mid)
  right = getSum(mid+1, end)

  # 가운데 부분 합하는 최댓값
  leftMax = -987987987
  leftSum = 0
  for i in range(mid, start-1, -1):
    leftSum += data[i]
    if leftSum >= leftMax:
      leftMax = leftSum
  
  rightMax = -987987987
  rightSum = 0
  for i in range(mid+1, end+1):
    rightSum += data[i]
    if rightSum > rightMax:
      rightMax = rightSum
  
  midMax = rightMax + leftMax

  # left, right, midMax 중 최댓값
  if left >= right and left >= midMax:
    return left
  elif right >= left and right >= midMax:
    return right
  else:
    return midMax
  
print(getSum(0, n-1))
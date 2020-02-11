T = int(input())
nums = [1, 1, [2, 4, 8, 6], [3, 9, 7, 1], [6, 4], 5, 6, [7, 9, 3, 1], [8, 4, 2, 6], [1, 9]]

def getFirstDigit(a, b):
  if a == 1 or a == 5 or a == 6:
    return nums[a]
  elif a == 0:
    return 10
  elif a == 4 or a == 9:
    return nums[a][b%2]
  else:
    return nums[a][b%4 -1]

for _ in range(0, T):
  tempArr = input().split(' ')
  a = int(tempArr[0][-1])
  b = int(tempArr[1])
  answer = getFirstDigit(a, b)
  print(answer)
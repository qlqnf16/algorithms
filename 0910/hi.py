def getArea(histogram):
  N = len(histogram)
  stack = []
  maxArea = 0

  for i in range(0, N):
    if len(stack) == 0:
      stack.append(i)
    else:
      while len(stack) > 0:
        top = stack[len(stack) - 1]
        if histogram[i] < histogram[top]:
          stack.pop()
          if len(stack) > 0:
            secondTop = stack[len(stack) -1]
          else:
            secondTop = -1
          tempMax = histogram[top] * (i - secondTop - 1)
          if tempMax > maxArea:
            maxArea = tempMax
        else:
          break
      stack.append(i)

  for i in range(len(stack)-1, -1, -1):
    if i == 0:
      if histogram[stack[i]] == 0:
        tempMax = 0
      else:
        tempMax = histogram[stack[i]] * N
    else:
      tempMax = histogram[stack[i]] * (len(stack) - i)
    if tempMax > maxArea:
      maxArea = tempMax

  print(maxArea)

while True:
  import random
  histogram = list(map(int, input().split(' ')))
  if histogram == [0]:
    break
  getArea(histogram[1:])
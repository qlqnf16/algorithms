N = int(input())
histogram = list(map(int, input().split(' ')))

stack = []
maxArea = N

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
  tempMax = histogram[stack[i]] * (len(stack) - i)
  if tempMax > maxArea:
    maxArea = tempMax

print(maxArea)
import sys

string = sys.stdin.readline()
bomb = input()
lenBomb = len(bomb)

stack = []
for s in string:
  if s == bomb[lenBomb - 1]:
    # 폭발 문자열과 일치하는지 체크
    explode = True
    tempLen = 1
    tempStack = []
    for i in range(1, lenBomb):
      if len(stack) == 0:
        break
      tempChr = stack.pop()
      tempLen += 1
      tempStack.append(tempChr)
      # 일치하지 않는 문자 만나면 break
      if tempChr != bomb[lenBomb -1 - i]:
        explode = False
        break
    if (not explode) or (tempLen != lenBomb):
      for _ in range(len(tempStack)):
        stack.append(tempStack.pop())
      stack.append(s)
  else:
    stack.append(s)

result = ''
if len(stack) <= 1:
  print('FRULA')
else:
  for i in range(0, len(stack) -1):
    result += stack[i]
  print(result)
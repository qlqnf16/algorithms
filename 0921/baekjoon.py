import re

def checkBalanced(string):
  pStack = []
  bStack = []
  for e in string:
    if e == '(':
      pStack.append(1)
    elif e == ')':
      if len(pStack) == 0:
        return False
      else:
        pStack.pop()
    elif e == '[':
      bStack.append(1)
    elif e == ']':
      if len(bStack) == 0:
        return False
      else:
        bStack.pop()
  if len(pStack) > 0 or len(bStack) > 0:
    return False
  else:
    return True

while True:
  line = input()
  if line == '.':
    break
  brackets = re.sub('\w+|\s', '', line)
  if checkBalanced(brackets):
    print('yes')
  else:
    print('no')
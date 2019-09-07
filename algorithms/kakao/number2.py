def checkRightPar(string):
  stack = []
  for s in string:
    if s == '(':
      stack.append('(')
    else:
      if len(stack) == 0:
        return False
      stack.pop()
  if len(stack) > 0:
    return False
  else:
    return True

def getBalancedPar(string):
  count = 0
  tempStr = ''
  for s in string: 
    tempStr += s
    if s == '(':
      count += 1
    else:
      count -= 1
    if count == 0:
      return tempStr
  if len(string) == 0:
    return ''

def makeNew(u, v):
  if checkRightPar(u):
    if v == '':
      return u
    else:
      newU = getBalancedPar(v)
      newV = v[len(newU):]
      return u + makeNew(newU, newV)
  else:
    tempStr = '('
    flippedU = u[1: len(u) -1].replace(')','_').replace('(',')').replace('_','(')
    newU = getBalancedPar(v)
    newV = v[len(newU):]
    return tempStr + makeNew(newU, newV) + ')' + flippedU
  

def solution(p):
  if checkRightPar(p):
    return p
  else:
    u = getBalancedPar(p)
    v = p[len(u):]
    return makeNew(u, v)


ps =["(()())()", ")(", "()))((()"]
for p in ps:
  print(solution(p))
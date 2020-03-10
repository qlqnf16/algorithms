data = {}
n, X, Y = map(int, input().split())
rootsOfX = []

for _ in range(1, n):
  parent, child = map(int, input().split())
  data[child] = parent

def getDistance(data, X, Y):
  if X == Y:
    return 0
  elif X == 0 or Y == 0:
    if X == 0:
      currentNode = Y
    else:
      currentNode = X
    distance = 0
    while True:
      if currentNode == 0:
        break
      currentNode = data[currentNode]
      distance += 1
    return distance
  else:
    currentNode = X
    while True:
      rootsOfX.append(currentNode)
      if currentNode == 0:
        break
      currentNode = data[currentNode]

    currentNode = Y
    distance = 0
    while True:
      if currentNode in rootsOfX:
        inx = rootsOfX.index(currentNode)
        distance += (inx)
        break
      else:
        currentNode = data[currentNode]
        distance += 1

  return distance

print(getDistance(data, X, Y))
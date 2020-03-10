data = {}
n, X, Y = map(int, input().split())
rootsOfX = []

for _ in range(1, n):
  parent, child = map(int, input().split())
  data[child] = parent

currentNode = X
while True:
  rootsOfX.append(data[currentNode])
  currentNode = data[currentNode]
  if currentNode == 0:
    break

currentNode = Y
while True:
  if data[currentNode] in rootsOfX:
    print(data[currentNode])
    break
  else:
    currentNode = data[currentNode]



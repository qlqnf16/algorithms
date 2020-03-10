tree = {}
n, r = map(int, input().split())
relations = [[] for _ in range(100)]

for _ in range(1, n):
  nodeOne, nodeTwo = map(int, input().split())
  relations[nodeOne].append(nodeTwo)
  relations[nodeTwo].append(nodeOne)

def findParent(parent, prevParent):
  for i in relations[parent]:
    if i != prevParent:
      print(i)
      tree[i] = parent
      findParent(i, parent)

findParent(r, -1)

def distanceFromRoot(node, root):
  distance = 0
  while True:
    if node == root:
      break
    node = tree[node]
    distance += 1
  return distance

maximum = 0
for i in range(0, len(relations)):
  if len(relations[i]) == 1 and i != r:
    tempMax = distanceFromRoot(i, r)
    if tempMax > maximum:
      maximum = tempMax

print(maximum)
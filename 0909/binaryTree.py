def preOrder(root, l, r):
  if root != -1:
    resultStack[0].append(root)
    if l != -1:
      preOrder(tree[l][0], tree[l][1], tree[l][2])
    if r != -1:
      preOrder(tree[r][0], tree[r][1], tree[r][2])

def inOrder(root, l, r):
  if root != -1:
    if l != -1:
      inOrder(tree[l][0], tree[l][1], tree[l][2])
    resultStack[1].append(root)
    if r != -1:
      inOrder(tree[r][0], tree[r][1], tree[r][2])

def postOrder(root, l, r):
  if root != -1:
    if l != -1:
      postOrder(tree[l][0], tree[l][1], tree[l][2])
    if r != -1:
      postOrder(tree[r][0], tree[r][1], tree[r][2])
    resultStack[2].append(root)

N = int(input())
tree = []
for _ in range(0, N):
  tree.append(list(map(int, input().split(' '))))

resultStack = [[],[],[]]

preOrder(tree[0][0], tree[0][1], tree[0][2])
inOrder(tree[0][0], tree[0][1], tree[0][2])
postOrder(tree[0][0], tree[0][1], tree[0][2])

for result in resultStack:
  print(' '.join(map(str, result)))
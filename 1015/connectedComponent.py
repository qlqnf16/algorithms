n, m = map(int, input().split())
myMax = n+1

graph = [[] for _ in range(myMax)]
reversedGraph = [[] for _ in range(myMax)]

for _ in range(m):
  a, b = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a)

check = [False]*myMax
order = []

def getTime(node):
  global check

  check[node] = True
  for n in graph[node]:
    if not check[n]:
      getTime(n)
  
  order.append(node)

check2 = [False]*myMax

def getGroup(node):
  global check2
  check2[node] = True

  for n in graph[node]:
    if not check2[n]:
      getGroup(n)

for i in range(1, n+1):
  if not check[i]:
    getTime(i)

groupCnt = 0
for i in range(len(order)-1, -1, -1):
  node = order[i]
  if not check2[node]:
    getGroup(node)
    groupCnt += 1

print(groupCnt)
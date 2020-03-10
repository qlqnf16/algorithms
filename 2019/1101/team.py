n = int(input())
myMax = n+1
students = [0]
students += list(map(int, input().split()))

graph = [[]]*myMax
reversedGraph = [[] for _ in range(myMax)]

for i in range(1,n+1):
  graph[i] = [students[i]]
  reversedGraph[students[i]].append(i)

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
group = [0]*myMax

def getGroup(node):
  global check2
  global group

  check2[node] = True
  group.append(node)

  for n in reversedGraph[node]:
    if not check2[n]:
      getGroup(n)
  

for i in range(1, n+1):
  if not check[i]:
    getTime(i)

count = 0
for i in range(len(order)-1, -1, -1):
  node = order[i]
  group = []
  if not check2[node]:
    getGroup(node)
    if len(group) <= 1 and node != students[node]:
      count += 1

print(count)
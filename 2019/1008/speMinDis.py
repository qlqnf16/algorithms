n, m = map(int, input().split())
myMax = n + 1

graph = [[] for _ in range(myMax)]
cost = [[] for _ in range(myMax)]

for _ in range(m):
  a, b, c = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a)

  cost[a].append(c)
  cost[b].append(c)

a, b = map(int, input().split())

def findMinimum(s, e):
  T = [987987987] * myMax
  check = [False] * myMax
  T[s] = 0

  for i in range(myMax):
    tempMin = 987987987
    minIndex = -1

    for j in range(myMax):
      if not check[j] and tempMin > T[j]:
        tempMin = T[j]
        minIndex = j

    check[minIndex] = True
    
    for j in range(len(graph[minIndex])):
      node = graph[minIndex][j]
      tempCost = cost[minIndex][j]
      if T[node] > T[minIndex] + tempCost:
        T[node] = T[minIndex] + tempCost
  
  return T[e]

first = findMinimum(1, a) + findMinimum(b, n)
second = findMinimum(1, b) + findMinimum(a, n)
aTob = findMinimum(a, b)

if first < second:
  print(first + aTob)
else:
  print(second + aTob)

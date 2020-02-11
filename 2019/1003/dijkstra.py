n, m, start, end = map(int, input().split())
graph = [[] for i in range(n)]
cost = [[] for i in range(n)]

for _ in range(m):
  a, b, c = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a)

  cost[a].append(c)
  cost[b].append(c)

T = [987987987] * n
check = [False] * n
T[start] = 0

for i in range(n):
  
  tempMin = 987987987
  minIndex = -1

  for j in range(n):
    if not check[j] and tempMin > T[j]:
      tempMin = T[j]
      minIndex = j

  check[minIndex] = True
  
  for j in range(len(graph[minIndex])):
    node = graph[minIndex][j]
    tempCost = cost[minIndex][j]
    if T[node] > T[minIndex] + tempCost:
      T[node] = T[minIndex] + tempCost

print(T)
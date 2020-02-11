n, m, k = map(int, input().split())
myMax = n + 1

graph = [[] for _ in range(myMax)]
cost = [[] for _ in range(myMax)]
reverseGraph = [[] for _ in range(myMax)]
reverseCost = [[] for _ in range(myMax)]

for _ in range(m):
  a, b, c = map(int, input().split())
  graph[a].append(b)
  cost[a].append(c)
  reverseGraph[b].append(a)
  reverseCost[b].append(c)

def findMinimum(s, go):
  T = [987987987] * myMax
  check = [False] * myMax
  T[s], T[0] = 0, 0

  for i in range(myMax):
    tempMin = 987987987
    minIndex = -1

    for j in range(myMax):
      if not check[j] and T[j] < tempMin:
        tempMin = T[j]
        minIndex = j
    
    check[minIndex] = True

    if go:
      for j in range(len(graph[minIndex])):
        node = graph[minIndex][j]
        tempCost = cost[minIndex][j]

        if T[node] > T[minIndex] + tempCost:
          T[node] = T[minIndex] + tempCost
    else:
      for j in  range(len(reverseGraph[minIndex])):
        node = reverseGraph[minIndex][j]
        tempCost = reverseCost[minIndex][j]

        if T[node] > T[minIndex] + tempCost:
          T[node] = T[minIndex] + tempCost
  
  return sum(T)

print(findMinimum(k, True) + findMinimum(k, False))
  
n, m = map(int, input().split())
graph = [[] for i in range(n)]

for _ in range(m):
  node1, node2 = map(int, input().split())
  graph[node1].append(node2)
  graph[node2].append(node1)

visited = [False]*n
result = []

def DFS(node, visited):
  result.append(node)
  visited[node] = True

  for n in graph[node]:
    if visited[n] == False:
      DFS(n, visited)

DFS(0, visited)

print(result)
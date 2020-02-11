## template
n = int(input())
m = int(input())
graph = [[] for i in range(n+1)]

for _ in range(m):
  node1, node2 = map(int, input().split())
  graph[node1].append(node2)
  graph[node2].append(node1)

visited = [False]*n
count = -1

def DFS(node, visited):
  global count
  visited[node] = True
  count += 1
  for n in graph[node]:
    if visited[n] == False:
      DFS(n, visited)

DFS(1,visited)
print(count)
n, m = map(int, input().split())
graph = [[] for i in range(n+1)]

for _ in range(m):
  node1, node2 = map(int, input().split())
  graph[node1].append(node2)
  graph[node2].append(node1)

visited = [False] * (n+1)
answer = 'YES'

def checkLinked(s, e):
  for n in graph[s]:
    if n == e:
      return True
  return False

def DFS(node, visited, prev):
  global answer
  visited[node] = True

  for n in graph[node]:
    if visited[n] == False:
      if checkLinked(n, prev):
        answer = 'NO'
        return
      DFS(n, visited, node)

DFS(1, visited, -1)
print(answer)
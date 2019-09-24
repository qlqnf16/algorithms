n, m = map(int, input().split())
graph = [[] for i in range(n)]

for _ in range(m):
  node1, node2 = map(int, input().split())
  graph[node1].append(node2)
  graph[node2].append(node1)

visited = [False] * n
colors = [False] * n
answer = 'YES'

def DFS(node, visited, prevColor):
  global answer
  color = not prevColor
  colors[node] = color
  visited[node] = True

  for n in graph[node]:
    if visited[n] == False:
      DFS(n, visited, color)
    else:
      if color == colors[n]:
        answer = 'NO'
        return answer

DFS(0, visited, True)
print(answer)
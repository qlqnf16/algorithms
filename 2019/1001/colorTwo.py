import queue

n, m = map(int, input().split())
graph = [[] for i in range(n)]
for _ in range(m):
  node1, node2 = map(int, input().split())
  graph[node1].append(node2)
  graph[node2].append(node1)

visited = [False]*n
color = [True]*n
q = queue.Queue()
q.put(0)
visited[0] = True
currentColor = False
answer = True

while q.qsize() > 0 and answer == True:
  currentNode = q.get()
  currentColor = color[currentNode]

  for n in graph[currentNode]:
    if visited[n] == False:
      visited[n] = True
      q.put(n)
      color[n] = not currentColor
    else:
      if color[n] == currentColor:
        answer = False
        break

if answer:
  print("YES")
else:
  print("NO")
import queue

n, m = map(int, input().split())
graph = [[] for i in range(n)]

for _ in range(m):
  node1, node2 = map(int, input().split())
  graph[node1].append(node2)
  graph[node2].append(node1)

visited = [False]*n
result = []
q = queue.Queue()
q.put(0)
visited[0] = True

while q.qsize() > 0:
  top = q.get()
  result.append(top)

  for n in graph[top]:
    if visited[n] == False:
      visited[n] = True
      q.put(n)

print(result)
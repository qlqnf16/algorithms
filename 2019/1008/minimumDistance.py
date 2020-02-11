import queue

n, m = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
  a, b = map(int, input().split())
  graph[a].append(b)
  graph[b].append(a)

s, e = map(int, input().split())

visit = [False]*n
q = queue.Queue()
q.put(s)
visit[s] = True
parent = [-1]*n
found = False

def getDistance(node, distance):
  if parent[node] == -1:
    print(distance)
  else:
    getDistance(parent[node], distance+1)

while q.qsize() > 0 and not found:
  top = q.get()

  for node in graph[top]:
    if not visit[node]:
      visit[node] = True
      q.put(node)
      parent[node] = top

    if node == e:
      distance = getDistance(node, 0)
      found = True
      break
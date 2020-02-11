import queue

n = int(input())
m = int(input())
graph = [[] for i in range(n+1)]

for _ in range(m):
  node1, node2 = map(int, input().split())
  graph[node1].append(node2) 
  graph[node2].append(node1) 

visited = [False] * (n+1)
q = queue.Queue()
q.put(1)
visited[1] = True
count = 0

while q.qsize() > 0:
  currentNode = q.get()
  
  for n in graph[currentNode]:
    if visited[n] == False:
      visited[n] = True 
      q.put(n)
      count += 1

print(count)
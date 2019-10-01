import queue

n, k = map(int, input().split())
visit = [False] * (n+1)

q = queue.Queue()
q.put(k)
visit[k] = True

while q.qsize() > 0:
  current = q.get()
  
  if current*2 <= n and visit[current*2] == False:
    visit[current*2] = True
    q.put(current*2)
  if current//3 > 0 and visit[current//3] == False:
    visit[current//3] = True
    q.put(current//3)

count = -1
for v in visit:
  if v == False:
    count += 1

print(count)

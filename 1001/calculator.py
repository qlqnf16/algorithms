import queue
n = int(input())
visit = [False] * 100000

q = queue.Queue()
q.put([1, 0])
visit[1] = True

while True:
  current, count = q.get()
  if current == n:
    print(count)
    break
  
  if current // 3 != 0 and visit[current//3] == False:
    visit[current//3] = True
    q.put([current // 3, count+1])
  if current * 2 <= 99999 and visit[current*2] == False:
    q.put([current * 2, count+1])
    visit[current*2] = True

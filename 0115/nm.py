def addNum(index):
  global n
  global visit
  global combination

  if index == m:
    print(" ".join(map(str, combination)))
    return

  for i in range(n):
    if not visit[i]:
      if index == 0 or combination[index-1] < i+1:
        combination[index] = i+1
        visit[i] = True
        addNum(index + 1)
        visit[i] = False

n, m = map(int, input().split())
visit = [False for _ in range(n)]
combination = [0 for _ in range(m)]
addNum(0)


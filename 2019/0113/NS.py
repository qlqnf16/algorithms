table = [[0] * 100 for _ in range(100)]
waiting = False

for t in range(10):
  input()

  for i in range(100):
    table[i] = list(map(int, input().split()))
  
  deadlock = 0
  for j in range(100):
    for i in range(100):
      if waiting and table[i][j] == 2:
        deadlock += 1
        waiting = False
        
      if table[i][j] == 1:
        waiting = True
    waiting = False
  
  print(f"#{t+1} {deadlock}")
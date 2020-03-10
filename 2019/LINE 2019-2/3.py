N = int(input())
toilet = []
for _ in range(N):
  toilet.append(list(map(int, input().split())))

toilet.sort()
occupied = []
count = 0
for i in range(N):
  if len(occupied) == 0:
    occupied.append(toilet[i])
    count += 1
  else:
    empty = False
    for j in range(len(occupied)):
      if occupied[j][1] <= toilet[i][0]:
        empty = True
        occupied[j] = toilet[i]
        break
    if not empty:
      occupied.append(toilet[i])
      count += 1

print(count)
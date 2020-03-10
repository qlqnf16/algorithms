N = int(input())
seat = list(map(int, input().split()))

prevIndx = -1
maxDistance = -1
maxIndx = 0
for i in range(N):
  if seat[i] == 1:
    if prevIndx >= 0 and maxDistance < i - prevIndx:
      maxDistance = i - prevIndx
      maxIndx = prevIndx
    prevIndx = i

print(maxDistance // 2)
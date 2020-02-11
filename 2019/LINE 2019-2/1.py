m, c = map(int, input().split())
messages = []
consumers = [0]*c
queIndx = 0

for _ in range(m):
  messages.append(int(input()))

count = 0

def checkEmptyArr(arr):
  for a in arr:
    if a != 0:
      return False
  return True

while True:
  for i in range(c):
    if consumers[i] != 0:
      consumers[i] -= 1
    if consumers[i] == 0 and queIndx < m:
      consumers[i] = messages[queIndx]
      queIndx += 1
  count += 1
  if checkEmptyArr(consumers):
    break

print(count - 1)
        
def visitCheckAndAppend(num):
  if num*2 < N+1 and towns[num*2] == 0:
    doubleQueue.append(num*2)
    towns[num*2] = 1
  if num//3 >= 0 and towns[num//3] == 0:
    devideQueue.append(num//3)
    towns[num//3] = 1

N, K = map(int, input().split(' '))
towns = [0]*(N+1)

doubleQueue = []
devideQueue = []

towns[K] = 1
visitCheckAndAppend(K)
while len(doubleQueue) > 0 or len(devideQueue) > 0:
  if len(doubleQueue) > 0:
    newTown = doubleQueue.pop(0)
    visitCheckAndAppend(newTown)
  elif len(devideQueue) > 0:
    newTown = devideQueue.pop(0)
    visitCheckAndAppend(newTown)

count = 0
for i in range(1, N+1):
  if towns[i] == 0:
    count += 1

print(count)
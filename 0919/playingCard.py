import sys

n = int(sys.stdin.readline())
cards = [0]
cards += (list(map(int, sys.stdin.readline().split())))
sumList = [0, cards[1]]

if n >= 2:
  sumList.append(cards[1]+cards[2])

for i in range(3, n+1):
  selTwo = cards[i] + sumList[i-2]
  selOne = cards[i] + cards[i-1] + sumList[i-3]
  selNone = sumList[i-1]
  sumList.append(max(selNone, selOne, selTwo))

print(sumList[n])
import sys

n = int(sys.stdin.readline())
scores = [0]*n

for i in range(0, n):
  scores[i] = list(map(int, sys.stdin.readline().split()))

  if i > 0:
    scores[i][0] += max(scores[i-1][1], scores[i-1][2])
    scores[i][1] += max(scores[i-1][0], scores[i-1][2])
    scores[i][2] += max(scores[i-1][0], scores[i-1][1])

print(max(scores[n-1])) 
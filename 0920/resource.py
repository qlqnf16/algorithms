import sys

N, M = map(int, sys.stdin.readline().split())
# maps = [ [ 0 for i in range(M) ] for j in range(N) ]
maps = []

for i in range(N):
  maps.append(list(map(int, sys.stdin.readline().split()))) 

n, m = 0, 0
dp = []
while n < N and m < M:
  
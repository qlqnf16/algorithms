import sys
myInput = sys.stdin.readline

N, M, Q = map(int, myInput().split())
tiles = [ [ 0 for i in range(M+1) ] for j in range(N+1) ]
sumList = [ [ 0 for i in range(M+1) ] for j in range(N+1) ]

for i in range(1, N+1):
  tile = list(map(int, myInput().split()))
  tiles[i] = [0]+tile
  tempSum = 0
  for j in range(1, M+1):
    tempSum += tiles[i][j]
    sumList[i][j] = tempSum + sumList[i-1][j]

for _ in range(0, Q):
  a, b, c, d = map(int, myInput().split())
  print(tiles[a+1][b+1], tiles[c+1][d+1])
  print(sumList[c+1][d+1] - sumList[c+1][b] - sumList[a][d+1] + sumList[1][b])
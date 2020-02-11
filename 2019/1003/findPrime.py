# 에라토스테네스의 체 이용

M, N = map(int, input().split())
array = [True]*1000001
array[1] = False

for i in range(N):
  if array[i] == True:
    for j in range(2, N):
      if i*j > 1000000:
        break
      array[i*j] = False

for i in range(M,N+1):
  if array[i] == True:
    print(i)
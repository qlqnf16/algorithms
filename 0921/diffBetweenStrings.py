A, B = input().split()

difCount = 987987987

for i in range(len(B) - len(A)+1):
  tempCount = 0
  for j in range(len(A)):
    if A[j] != B[i+j]:
      tempCount += 1
  if tempCount < difCount:
    difCount = tempCount

print(difCount)
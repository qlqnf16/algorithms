A = input()
B = input()

for i in range(len(B)):
  if A[i] == B[i]:
    

count = 0
for i in range(len(B)):
  if A[i] != B[i]:
    A = A[:i] + B[i] + A[i:]
    count += 1

count += len(B) - len(A)
print(count)
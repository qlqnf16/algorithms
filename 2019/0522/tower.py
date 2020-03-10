N = int(input())
stack = []
result = []

tower = list(map(int, input().split()))

for i in range(0, N):
    while True:
        if len(stack) == 0:
            result.append(0)
            stack.append(i)
            break
        temp = stack.pop()
        if tower[temp] > tower[i]:
            result.append(temp+1)
            stack.append(temp)
            stack.append(i)
            break

print(' '.join(str(x) for x in result))
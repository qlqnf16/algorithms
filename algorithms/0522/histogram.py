n = int(input())
his = list(map(int, input().split()))

sqmax = min(his)*n
stack = []

for h in his:
    count = 2
    if len(stack) == 0:
        stack.append(h)
    else:
        temp = stack.pop()
        if temp >= h:
            while len(stack):
                temp = stack.pop()
                tempsq = ''
            stack.append(h)
        else:
            stack.append(temp)
            stack.append(h)

print(sqmax)
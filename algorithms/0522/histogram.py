n = int(input())
his = list(map(int, input().split()))

sqmax = min(his)*n
stack = []

for h in his:
    if len(stack) == 0:
        stack.append(h)
    else:
        temp = stack.pop()
        count = 2
        if temp <= h:  
            while temp <= h:
                if sqmax < temp * count:
                    sqmax = temp * count
                if len(stack):
                    temp = stack.pop()
                    count += 1
                else:
                    stack.append(h)
                    break
        else:
            while temp > h:
                if sqmax < h * count:
                    sqmax = h * count
                if len(stack):
                    temp = stack.pop()
                    count += 1
                else:
                    stack.append(h)
                    break

print(sqmax)
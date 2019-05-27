dishes = input()
array = []
order = 97
stackArray = []

for dish in dishes:
    if order <= ord(dish):
        tempOrder = ord(dish)
        for i in range(order, tempOrder + 1):
            array.append(chr(i))
            stackArray.append("push")
        array.pop()
        stackArray.append("pop")
        order = tempOrder + 1
    else:
        if array[-1] == dish:
            array.pop()
            stackArray.append("pop")
        else:
            stackArray.append(0)
            break

if stackArray[-1] == 0:
    print("impossible")
else:
    print("\n".join(stackArray))

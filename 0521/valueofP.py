myPS = input()
psArray = []

for p in myPS:
    if p == "(" or p == "[":
        psArray.append(p)
    elif p == ")":
        if len(psArray) != 0 and psArray[-1] == "(":
            psArray.pop()
        else:
            psArray.append(p)
            break
    else:
        if len(psArray) != 0 and psArray[-1] == "[":
            psArray.pop()
        else:
            psArray.append(p)
            break


def calPS(ps):
    array = []
    for p in ps:
        if p == "(" or p == "[":
            array.append(p)
        else:
            mysum = 0
            while type(array[-1]) is int:
                mysum += array.pop()
            array.pop()
            if mysum != 0:
                if p == ")":
                    array.append(mysum * 2)
                else:
                    array.append(mysum * 3)
            else:
                if p == ")":
                    array.append(2)
                else:
                    array.append(3)
    result = 0
    while len(array) > 0:
        result += array.pop()
    return result


if len(psArray) > 0:
    print(0)
else:
    print(calPS(myPS))

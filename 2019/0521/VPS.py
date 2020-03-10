myPS = input()
psArray = []

for p in myPS:
    if p == "(":
        psArray.append(p)
    else:
        if len(psArray) != 0:
            psArray.pop()
        else:
            psArray.append(p)
            break

if len(psArray) == 0:
    print("YES")
else:
    print("NO")

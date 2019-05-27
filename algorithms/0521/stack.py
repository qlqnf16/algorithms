class Stack:
    def __init__(self, length):
        self.array = []
        self.length = length

    def push(self, x):
        if len(self.array) >= self.length:
            print("Overflow")
        else:
            self.array.append(x)

    def pop(self):
        if len(self.array) == 0:
            print("Underflow")
        else:
            self.array.pop()

    def top(self):
        if len(self.array) == 0:
            print("NULL")
        else:
            print(self.array[len(self.array) - 1])


n, m = map(int, input().split())
stack = Stack(n)
for _ in range(0, m):
    tempList = input().split()
    if tempList[0] == "1":
        stack.push(tempList[1])
    elif tempList[0] == "2":
        stack.pop()
    else:
        stack.top()

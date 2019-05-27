class Queue:
    def __init__(self, size):
        self.array = [0]*size
        self.size = size
        self.front = 0
        self.rear = 0

    def push(self, num):
        if self.rear >= self.size:
            print("Overflow")
        else:
            self.array[self.rear] = num
            self.rear += 1
    
    def pop(self):
        if self.rear - self.front == 0:
            print("Underflow")
        else:
            self.front += 1
    
    def Front(self):
        if self.rear - self.front == 0:
            print("NULL")
        else:
            print(self.array[self.front])

n, m = map(int, input().split())
queue = Queue(n)

for _ in range(0, m):
    inputs = input().split()
    if inputs[0] == '1':
        queue.push(inputs[1])
    elif inputs[0] == '2':
        queue.pop()
    else:
        queue.Front()
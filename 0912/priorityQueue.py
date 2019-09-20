## 우선순위 큐 힙으로 구현하기

class PriorityQueue():
  def __init__(self):
    self.data = [0]
  
  def push(self, x):
    self.data.append(x)
    index = len(self.data) - 1
    
    while index >= 1:
      if self.data[index] < self.data[index//2]:
        self.data[index], self.data[index//2] = self.data[index//2], self.data[index]
        index = index // 2
      else:
        break
  
  def pop(self):
    self.data[1] = self.data[len(self.data) - 1]
    self.data.pop()
    
    index = 1
    while True:
      if index*2 >= len(self.data):
        break
      elif index*2+1 >= len(self.data):
        pIndex = index*2
      else:
        if self.data[index*2] < self.data[index*2+1]:
          pIndex = index*2
        else:
          pIndex = index*2+1
      
      if self.data[index] > self.data[pIndex]:
        self.data[index], self.data[pIndex] = self.data[pIndex], self.data[index]
        index = pIndex
      else:
        break
      
  def top(self):
    return self.data[1]

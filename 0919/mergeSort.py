import sys

n = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))

def mergeSort(start, end):
  if start >= end:
    return [data[start]]

  mid = start + (end-start) // 2
  leftArr = mergeSort(start, mid)
  rightArr = mergeSort(mid+1, end)

  # left, right 합치기
  newArr = []
  l, r = 0, 0
  while True:
    if leftArr[l] <= rightArr[r]:
      newArr.append(leftArr[l])
      l += 1
    else:
      newArr.append(rightArr[r])
      r += 1
    if l >= len(leftArr):
      newArr += rightArr[r:]
      break
    if r >= len(rightArr):
      newArr += leftArr[l:]
      break
  
  return newArr

print(' '.join(str(i) for i in mergeSort(0, n-1)))

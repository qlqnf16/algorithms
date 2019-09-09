tempSum = 1000000000
numArray = [0, 0]

def trySum(array, index, start, end):
    global tempSum, numArray
    while start + 1 < end:
        mid = (start + end) // 2
        mySum = array[index] + array[mid] 
        if mySum < 0:
            start = mid
        else:
            end = mid
    if abs(array[index] + array[start]) > abs(array[index] + array[end]):
        mySum = array[index] + array[end]
        finInd = end
    else:
        mySum = array[index] + array[start]
        finInd = start
    if abs(mySum) < abs(tempSum):
        tempSum = mySum
        numArray[0] = array[index]
        numArray[1] = array[finInd]

n = int(input())
array = list(map(int, input().split(' ')))
array.sort()
for i in range(0, n-1):
    trySum(array, i, i+1, n-1)
print(' '.join(str(a) for a in numArray))
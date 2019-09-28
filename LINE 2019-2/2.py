nums = list(map(int, input().split()))
l = len(nums)
k = int(input())
count = 1
check = [False]*10

nums.sort()

def makeSequence(index, arr):
  global nums
  global l
  global check
  global k
  global count

  if index >= l:
    if count == k:
      print(''.join(str(a) for a in arr))
    count += 1
  else:
    for i in range(l):
      if not check[i]:
        arr.append(nums[i])
        check[i] = True
        makeSequence(index+1, arr)
        arr.pop()
        check[i] = False

arr = []
makeSequence(0, arr)

      



# for (int i = 0; i < n; i ++){
# if (check[i] != true){
#     int num = 97 + i;
#     arr.setCharAt(index, (char)num);
#     // arr[index] = new Character((char)num).toString();
#     check[i] = true;
#     soon(index+1, n, r, arr, check);
#     check[i] = false;
# }
# }    
def checkPelindrome(length, arr, isVertical, index, start):
  isPelindrome = True
  end = start + length - 1
  if isVertical:
    while start < end:
      if arr[start][index] != arr[end][index]:
        isPelindrome = False
        break
      start += 1
      end -= 1
  else:
    while start < end:
      if arr[index][start] != arr[index][end]:
        isPelindrome = False
        break
      start += 1
      end -= 1
  return isPelindrome

for t in range(1, 11):
  charTable = []
  count = 0
  length = int(input())
  for i in range(8):
    charTable.append(list(input()))

  for i in range(8):
    for j in range(9-length):
      if checkPelindrome(length, charTable, False, i, j):
        count += 1

  for j in range(8):
    for i in range(9-length):
      if checkPelindrome(length, charTable, True, j, i):
        count += 1

  print(f"#{t} {count}")

  
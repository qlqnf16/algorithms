#level D3

for case in range(1, 11):
  dumpCnt = int(input())
  boxes = list(map(int, input().split()))
  done = False

  for cnt in range(dumpCnt):
    maxnow = max(boxes)
    minnow = min(boxes)
    maxIndex = boxes.index(maxnow)
    minIndex = boxes.index(minnow)

    boxes[maxIndex] -= 1
    boxes[minIndex] += 1

    if boxes[maxIndex] - boxes[minIndex] <= 0:
      done = True
      break

  if not done:
    answer = max(boxes) - min(boxes)

  print(f"#{case} {answer}")
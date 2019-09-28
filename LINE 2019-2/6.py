# 정렬방식
# 1. TOP => 출력 여백
# 2. MIDDLE => (2max-1) - (2current-1) // 2 여백 출력 여백
# 3. BOTTOM => (2max-1) - (2current-1) 여백 출력

# 숫자인쇄
# 가로x: 3 이상의 홀수
# 1: x-1 . 1 *
# 2: x * => (x//2) 만큼 x-1 . 1 * => x * => (x//2) 만큼 1 * x-1 . => x *
# 3: x * => (x//2) 만큼 x-1 . 1 * => x * => (x//2) 만큼 x-1 . 1 * => x *
# 4: (x//2) 만큼 1 * x - 2 . 1 * => x * => (x//2) 만큼 x-1 . 1 *
# 5: x * => (x//2) 만큼 1 * x-1 * => x * => (x//2) 만큼 x-1 . 1 * . => x *
# 6: (x//2+1) 만큼 1 * x-1 . => x * => (x//2) 만큼 1 * x-2 . 1 * . => x *
# 7: 1번 x*3 나머지 x-1 . 1 *
# 8: 3 => 가운데 공백 => 3 => 가운데 공백 => 3
# 9: 3 => 가운데 공백 => 3 => 오른쪽
# 점찍기
def whole(x):
  return '#'*x
def between(x):
  return f'#{"."*(x-2)}#'
def left(x):
  return f'#{"."*(x-1)}'
def right(x):
  return f'{"."*(x-1)}#'

# 숫자그리기
def printNum(num, width):
  height = width*2 - 1
  result = []

  for i in range(1, height+1):
    if num == '1':
      result.append(right(width))
    elif num == '2':
      if i == 1 or i == height or i == height // 2+1:
        result.append(whole(width))
      elif i > 1 and i < height // 2+1:
        result.append(right(width))
      else:
        result.append(left(width))
    elif num == '3':
      if i == 1 or i == height or i == height // 2+1:
        result.append(whole(width))
      else:
        result.append(right(width))
    elif num == '4':
      if i == height // 2+1:
        result.append(whole(width))
      elif i < height//2+1:
        result.append(between(width))
      else:
        result.append(right(width))
    elif num == '5':
      if i == 1 or i == height or i == height // 2+1:
        result.append(whole(width))
      elif i > 1 and i < height // 2+1:
        result.append(left(width))
      else:
        result.append(right(width))
    elif num == '6':
      if i == height or i == height // 2+1:
        result.append(whole(width))
      elif i < height // 2+1:
        result.append(left(width))
      else:
        result.append(between(width))
    elif num == '7':
      if i == 1:
        result.append(whole(width))
      else:
        result.append(right(width))
    elif num == '8':
      if i == 1 or i == height or i == height // 2+1:
        result.append(whole(width))
      else:
        result.append(between(width))
    elif num == '9':
      if i == 1 or i == height // 2+1:
        result.append(whole(width))
      elif i > 1 and i < height // 2+1:
        result.append(between(width))
      else:
        result.append(right(width))
    elif num == '0':
      if i == 1 or i == height:
        result.append(whole(width))
      else:
        result.append(between(width))
  
  return result

#  시작
case, align = input().split()
maxWidth = 0
data = []
for _ in range(int(case)):
  width, string = input().split()
  data.append([int(width), string])
  if int(width) > maxWidth:
    maxWidth = int(width)

maxHeight = maxWidth*2 - 1
for i in range(1, maxHeight+1):
  arr = []

  for d in data:
    height = d[0]*2 - 1
    if d[0] < maxWidth:
      for num in d[1]:
        if align == 'TOP':
          if i > height:
            arr.append('.'*d[0])
          else:
              arr.append(printNum(num, d[0])[i-1])
        elif align == 'MIDDLE':
          if not (1 + (maxHeight-height)//2 <= i <= maxHeight - (maxHeight-height)//2 ):
            arr.append('.'*d[0])
          else:
              arr.append(printNum(num, d[0])[i-((maxHeight-height)//2)-1])          
        else:
          if i < height:
            arr.append('.'*d[0])
          else:
              arr.append(printNum(num, d[0])[i-height])
    else:
      for num in d[1]:
        arr.append(printNum(num, d[0])[i-1])
  
  print(' '.join(arr))
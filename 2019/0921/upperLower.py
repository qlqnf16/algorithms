# input: AAABBBBBCCCCDDDDEFFF
# output: 3A5B4C4DE3F

string = input()
count = 1
prevChar = string[0]

result = ''

for i in range(1, len(string)+1):
  if i == len(string) or string[i] != prevChar:
    if count == 1:
      result += prevChar
    else:
      result += f'{count}{prevChar}'
    if i != len(string):
      count = 1
      prevChar = string[i]
  else:
    count += 1

print(result)    

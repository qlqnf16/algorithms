import re 

def getListofSet(s):
  array = s.split("}")
  result = []
  for ele in array:
    temp = set()
    p = re.compile('\d+')
    m = set(map(int, p.findall(ele)))
    if len(m) > 0:
      result.append(m)

  result.sort(key=len)
  return result

def solution(s):
  answer = []
  arr = getListofSet(s)
  answer.append(list(arr[0])[0])
  for i in range(1, len(arr)):
    add = list(arr[i] - arr[i-1])[0]
    answer.append(add)

  print(answer)
  return answer

solution("{{2},{2,1},{2,1,3},{2,1,3,4}}")
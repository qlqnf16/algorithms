import re
import itertools

def checkDuplicated(banned_id):
  checkDict = {}
  for banned in banned_id:
    if banned in checkDict:
      checkDict[banned] += 1
    else:
      checkDict[banned] = 1
  return checkDict

def getMatches(target, banned_id):
  regex = banned_id.replace("*", ".")
  p = re.compile(regex)
  m = p.match(target)
  if m != None:
    return True

def solution(user_id, banned_id):
    matches = []
    for banned in banned_id:
      match = []
      for user in user_id:
        if len(user) == len(banned) and getMatches(user,banned):
          match.append(user)
      matches.append(match)

    result = list(itertools.product(*matches))
    answer = 0
    sets = []
    for res in result:
      if len(set(res)) == len(res) and set(res) not in sets:
        print(res)
        sets.append(set(res))
        answer += 1

    return answer

user_id = ["frodo", "fradi", "crodo", "abc123", "frodoc"]
# banned_id = ["fr*d*", "abc1**"]
banned_id = ["*rodo", "*rodo", "******"]
# banned_id =["fr*d*", "*rodo", "******", "******"]
print(solution(user_id, banned_id))
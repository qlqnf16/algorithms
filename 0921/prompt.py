N = int(input())
results = []
for i in range(N):
  results.append(input())

length = len(results[0])
searchString = ''

for i in range(length):
  areSame = True
  for j in range(N-1):
    if results[j][i] != results[j+1][i]:
      searchString += '?'
      areSame = False
      break
  if areSame:
    searchString += results[0][i]

print(searchString)
for t in range(1, 11):
  length = int(input())
  buildings = list(map(int, input().split()))
  count = 0

  for i in range(2, length-2):
    height = buildings[i]
    maxNeighbour = max([buildings[i+1], buildings[i+2], buildings[i-1], buildings[i-2]])
    if maxNeighbour < height:
      count += height - maxNeighbour
  
  print(f"#{t} {count}")
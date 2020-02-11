for t in range(1, 11):
  size = int(input())
  crypto = list(input().split())
  instructionSize = int(input())
  instructions = list(input().split())
  
  i = 0
  while i < instructionSize:
    command = instructions[i]

    if command == 'I':
      insertIndx = int(instructions[i+1])
      insertRange = int(instructions[i+2])
      if insertIndx < 10:
        for r in range(insertRange):
          crypto.insert(insertIndx+r, instructions[i+3+r])
      i += 3 + insertRange
    elif command == 'D':
      deleteStart = int(instructions[i+1])
      deleteNum = int(instructions[i+2])
      if deleteStart < 10:
        del crypto[deleteStart : deleteStart+deleteNum]
      i += 3
    elif command == 'A':
      appendNum = int(instructions[i+1])
      for r in range(appendNum):
        crypto.append(instructions[i+2+r])
      i += 2 + appendNum
  
  print(f"#{t} " + " ".join(crypto[:10]))

  
      
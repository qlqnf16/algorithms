def returnNewBoard(board):
  size = len(board)
  newBoard = [[] for _ in range(size)]
  for i in range(size-1, -1, -1):
    for j in range(0, size):
      if board[i][j] > 0:
        newBoard[j].append(board[i][j])
  return newBoard



def solution(board, moves):
    answer = 0
    newBoard = returnNewBoard(board)
    stack = []

    for move in moves:
      target = newBoard[move-1]
      if len(target) > 0:
        movedChar = target.pop()
        if len(stack) > 0:
          compareChar = stack.pop()
          if compareChar == movedChar:
            answer += 2
          else:
            stack.append(compareChar)
            stack.append(movedChar)
        else:
          stack.append(movedChar)

    return answer
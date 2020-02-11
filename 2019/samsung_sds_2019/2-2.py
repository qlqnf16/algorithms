T = int(input())
N = int(input())

# initial setting
game = []
max_num = 0
for i in range(0, N):
    line_input = list(map(int, input().split()))
    temp_max = max(line_input)
    game.append(line_input)
    if temp_max > max_num:
        max_num = temp_max

visit_check = [0]*(max_num+1)
max_flip = 0    

# 탐색 function
def checkRoute(w, h, flip, max_flip):
    moved = False
    # if visit_check[game[w][h]] == 0:
    flip += 1
    visit_check[game[w][h]] += 1
    # print(f'{w}, {h}: {flip}')
    if w-1 >= 0 and game[w][h] < game[w-1][h]:
        # print(f'{w}, {h}: {flip}')
        checkRoute(w-1, h, flip, max_flip)
        moved = True
    if w+1 < N and game[w][h] < game[w+1][h]:
        # print(f'{w}, {h}: {flip}')
        checkRoute(w+1, h, flip, max_flip)
        moved = True
    if h-1 >= 0 and game[w][h] < game[w][h-1]:
        # print(f'{w}, {h}: {flip}')
        checkRoute(w, h-1, flip, max_flip)    
        moved = True

    if h+1 < N and game[w][h] < game[w][h+1]:
        # print(f'{w}, {h}: {flip}')
        checkRoute(w, h+1, flip, max_flip)
        moved = True
    if not moved:
        return flip
# 탐색

print(checkRoute(0, 0, 0, 0))


# for w in range(0, N):
#     for h in range(0, N):
#         flip = checkRoute(w, h, 0)
#         visit_check[game[w][h]] = 1

print(visit_check)
# print(f'답: {flip}')


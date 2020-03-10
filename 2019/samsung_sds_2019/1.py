T = int(input())
for t in range(1, T+1):
    N, K = map(int, input().split())
    papers = list(map(int, input().split()))
    
    paper_list = [0] * K
    for i in range(1, K+1):
        if i in papers:
            paper_list[i-1] = 1
            
    max_papers = 0
    if 0 not in paper_list:
        for i in range(0, K+1):
            

    print(f'#{t} {max_papers}')
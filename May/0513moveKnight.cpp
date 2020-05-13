#include <cstdio>
#include <queue>
#define MAX 300
using namespace std;

int N, sr, sc, gr, gc;
int board[MAX+2][MAX+2];
int visit[MAX+2][MAX+2];
int dir[][8] = {{-2, -2, -1, -1, 1, 1, 2, 2}, {-1, 1, -2, 2, -2, 2, -1, 1}};
typedef struct {
    int r, c, d;
} POS;

int bfs(int r, int c, int u) {
    int d, nr, nc;
    queue<POS> posQueue;
    posQueue.push({r, c, 0});
    visit[r][c] = u;
    
    while (!posQueue.empty()) {
        r = posQueue.front().r;
        c = posQueue.front().c;
        d = posQueue.front().d;
        posQueue.pop();
        if (r == gr && c == gc) return d;
        
        for (int i = 0; i < 8; i++) {
            nr = r + dir[0][i];
            nc = c + dir[1][i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (visit[nr][nc] == u) continue;
            visit[nr][nc] = u;
            posQueue.push({nr, nc, d+1});
        }
    }
    
    return -1;
}

int solve(int t) {
    scanf("%d", &N);
    scanf("%d %d %d %d", &sr, &sc, &gr, &gc);
    return bfs(sr, sc, t);
}

int main() {
    int T, ans;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        ans = solve(i);
        printf("%d\n", ans);
    }
    
    return 0;
}

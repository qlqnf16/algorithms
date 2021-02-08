#include <stdio.h>
#define MAX 20

int R, C, maxx;
char board[MAX+2][MAX+2];
bool visit[26];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

void dfs(int r, int c, int dist) {
    int nr, nc;
    char ch = board[r][c];
    if (dist > maxx) maxx = dist;
    
    for (int i = 0; i < 4; i++) {
        nr = r + dir[0][i];
        nc = c + dir[1][i];
        ch = board[nr][nc];
        if (!board[nr][nc] || visit[ch-'A']) continue;
        visit[ch-'A'] = true;
        dfs(nr, nc, dist+1);
        visit[ch-'A'] = false;
    }
}

int solve() {
    visit[board[1][1]-'A'] = true;
    dfs(1, 1, 1);
    return maxx;
}

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; i++) {
        scanf("%s", &board[i][1]);
    }
    int ans = solve();
    printf("%d", ans);
    
    return 0;
}

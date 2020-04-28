#include <stdio.h>

int ans;
bool haveBomb = true;
char map[15][7];
int dir[][3] = {{-1, -1, -1}, {-1, 0, 1}};

void input() {
    for (int i = 1; i <= 13; i++) {
        scanf("%s", &map[i][1]);
    }
}

void useBomb(int c, bool back) {
    for (int i = c-5; i <= c+5; i++) {
        if (i < 1) continue;
        if (i > 13) break;
        for (int j = 1; j <= 5; j++) {
            if (!back && map[i][j] == 'X') map[i][j] = '2';
            if (back && map[i][j] == '2') map[i][j] = 'X';
        }
    }
    haveBomb = back;
}

void dfs(int c, int r, int sum) {
    int nc, nr;
    if (c <= 1) {
        if (sum > ans) ans = sum;
        return;
    }
    
    if (haveBomb) {
        useBomb(c, false);
        for (int i = 0; i < 3; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            if (nr < 1 || nr > 5) continue;
            if (map[nc][nr] == '*') dfs(nc, nr, sum + 10);
            else if (map[nc][nr] == 'X') dfs(nc, nr, sum - 7);
            else dfs(nc, nr, sum);
        }
        useBomb(c, true);
    }
    for (int i = 0; i < 3; i++) {
        nc = c + dir[0][i];
        nr = r + dir[1][i];
        if (nr < 1 || nr > 5) continue;
        if (map[nc][nr] == '*') dfs(nc, nr, sum + 10);
        else if (map[nc][nr] == 'X') dfs(nc, nr, sum - 7);
        else dfs(nc, nr, sum);
    }
}

void solve() {
    dfs(13, 3, 0);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        haveBomb = true; ans = -987987987;
        input();
        solve();
        printf("%d\n", ans);
    }
    
    return 0;
}

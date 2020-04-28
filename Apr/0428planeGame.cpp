#include <stdio.h>

int ans;
int coins[15], enemies[15];
bool haveBomb;
char map[15][7];
int dir[][3] = {{-1, -1, -1}, {-1, 0, 1}};

void input() {
    for (int i = 1; i <= 13; i++) {
        scanf("%s", &map[i][1]);
    }
}

int useBomb(int c, bool back) {
    int changed = 0;
    for (int i = c-5; i < c; i++) {
        if (i < 1) continue;
        for (int j = 1; j <= 5; j++) {
            if (!back && map[i][j] == 'X') {
                map[i][j] = '2';
                changed = 1;
            }
            if (back && map[i][j] == '2') map[i][j] = 'X';
        }
    }
    haveBomb = back;
    return changed;
}

void dfs(int c, int r, int sum) {
    int nc, nr, changed = 1;
    if (sum + coins[c-1]*10 < ans) return;
    if ((!coins[c-1] && !enemies[c-1]) || c <= 1) {
        if (sum > ans) ans = sum;
        return;
    }
    
    int t = c - 6 < 1 ? 0 : c-6;
    if ((enemies[c-1] - enemies[t]) && haveBomb) {
        changed = useBomb(c, false);
        for (int i = 0; i < 3; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            if (nr < 1 || nr > 5) continue;
            if (map[nc][nr] == '*') dfs(nc, nr, sum + 10);
            else if (map[nc][nr] == 'X') dfs(nc, nr, sum - 7);
            else dfs(nc, nr, sum);
        }
        if (changed) useBomb(c, true);
    }
    if (changed) {
        for (int i = 0; i < 3; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            if (nr < 1 || nr > 5) continue;
            if (map[nc][nr] == '*') dfs(nc, nr, sum + 10);
            else if (map[nc][nr] == 'X') dfs(nc, nr, sum - 7);
            else dfs(nc, nr, sum);
        }
    }
}

void solve() {
    int coin, enemy;
    for (int i = 1; i <= 13; i++) {
        coin = enemy = 0;
        for (int j = 1; j <= 5; j++) {
            if (map[i][j] == '*') coin++;
            if (map[i][j] == 'X') enemy++;
        }
        coins[i] = coins[i-1] + coin;
        enemies[i] = enemies[i-1] + enemy;
    }
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

#include <stdio.h>
char board[14][9];
int visit[14][9];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
int tempLoc[80][2];
int cnt;

void input() {
    for (int i = 1; i <= 12; i++) {
        scanf("%s", &board[i][1]);
    }
}

void dfs(int c, int r, int link) {
    int nc, nr;
    visit[c][r] = link;
    tempLoc[cnt][0] = c;
    tempLoc[cnt][1] = r;
    
    for (int i = 0; i < 4; i++) {
        nc = c + dir[0][i];
        nr = r + dir[1][i];
        if (board[nc][nr] != board[c][r]) continue;
        if (visit[nc][nr] == link) continue;
        cnt ++;
        dfs(nc, nr, link);
    }
}

void markRemove(int cnt) {
    int c, r;
    for (int i = 1; i <= cnt; i++) {
        c = tempLoc[i][0];
        r = tempLoc[i][1];
        board[c][r] = 'X';
    }
}

void removeBbuyo(int link) {
    int removed;
    
    for (int j = 1; j <= 6; j++) {
        removed = 0;
        for (int i = 12; i > 0; i--) {
            if (board[i][j] == 'X') {
                removed ++;
                if (removed >= 6) board[i][j] = '.';
            } else {
                if (!removed) continue;
                board[i+removed][j] = board[i][j];
                board[i][j] = '.';
            }
        }
    }
}

int solve() {
    int link;
    bool removed;
    for (link = 1;; link++) {
        removed = false;
        for (int i = 12; i > 0; i--) {
            for (int j = 1; j <= 6; j++) {
                if (board[i][j] != '.' && visit[i][j] < link) {
                    cnt = 1;
                    dfs(i, j, link);
                    if (cnt >= 4) {
                        removed = true;
                        markRemove(cnt);
                    }
                }
            }
        }
        if (!removed) break;
        removeBbuyo(link);
    }
    
    return link-1;
}

void initialize() {
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= 6; j++) {
            visit[i][j] = 0;
        }
    }
}

int main() {
    int T, ans;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        initialize();
        input();
        ans = solve();
        printf("%d\n", ans);
    }
}


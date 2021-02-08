#include <stdio.h>
#define MAX 10

int N, totalPipe, linkedPipe;
int sc, sr;
char map[MAX+2][MAX+2];
bool pipe[MAX+2][MAX+2][4];
int dir[][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}}; //상하좌우
int nextDir[] = {1, 0, 3, 2};
int pipeNumCheck[][4] = {{0, 0, 0, 0}, {0, 0, 1, 1}, {1, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {1, 0, 1, 0}, {1, 0, 0, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 1, 1}};

void fillPipe(int c, int r, char pnum) {
    int newidx;
    if (pnum == '0') return;
    if (pnum <= '9') newidx = pnum - '0';
    else newidx = pnum - 'A' + 10;
    totalPipe++;
    for (int i = 0; i < 4; i++) {
        pipe[c][r][i] = pipeNumCheck[newidx][i];
     }
}

void floodFill(int c, int r, int prev) {
    if (prev != -1 && !pipe[c][r][prev]) return;
    if (map[c][r] == 'C') return;
    linkedPipe++;
    map[c][r] = 'C';
    for (int i = 0; i < 4; i++) {
        if (!pipe[c][r][i]) continue;
        floodFill(c + dir[0][i], r + dir[1][i], nextDir[i]);
    }
}

int solve() {
    int res;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            fillPipe(i, j, map[i][j]);
        }
    }
    floodFill(sc+1, sr+1, -1);
    res = totalPipe - linkedPipe;
    
    return res;
}

int main() {
    int ans;
    scanf("%d", &N);
    scanf("%d %d", &sr, &sc);
    for (int i = 1; i <= N; i++) {
        scanf("%s", &map[i][1]);
    }
    ans = solve();
    printf("%d", ans);

    return 0;
}


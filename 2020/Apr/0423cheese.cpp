#include <stdio.h>
#define MAX 102

int C, R, totalCheese, removedCheese;
int board[MAX][MAX];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
 
void floodFill(int c, int r) {
    if (c < 0 || c >= C || r < 0 || r >= R) return;
    if (board[c][r] == 2 || board[c][r] == -1) return;
    if (board[c][r] == 1) {
        board[c][r] = -1;
        removedCheese++;
        return;
    }
    board[c][r] = 2;
    for (int i = 0; i < 4; i++) {
        floodFill(c + dir[0][i], r + dir[1][i]);
    }
}

void init() {
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            if (board[i][j] == -1) board[i][j] = 0;
            if (board[i][j] == 2) board[i][j] = 0;
        }
    }
}

void solve() {
    int time = 1;
    for (int t = 0; ; t++) {
        removedCheese = 0;
        floodFill(0, 0);
        if (totalCheese <= removedCheese) break;
        totalCheese -= removedCheese;
        init();
        time++;
    }
    printf("%d\n%d", time, totalCheese);
}
int main() {
    scanf("%d %d", &C, &R);
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j]) totalCheese ++;
        }
    }
    solve();

    return 0;
}

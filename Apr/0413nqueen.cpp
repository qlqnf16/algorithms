#include <cstdio>
using namespace std;
#define MAX 16

int N, cnt;
int board[MAX][MAX];
bool visitRow[MAX];

bool checkPossible(int c, int r) {
    if (visitRow[r]) return false;
    for (int i = 1;;i++) {
        if (c-i < 0) break;
        if (r-i >= 0 && board[c-i][r-i]) return false;
        if (r+i < N && board[c-i][r+i]) return false;
    }
    return true;
}

void printBoard(void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(int c) {
    if (c >= N) {
        cnt ++;
        printBoard();
        return;
    }
    for (int i = 0; i < N; i++) {
        if (checkPossible(c, i)) {
            visitRow[i] = true;
            board[c][i] = 1;
            dfs(c+1);
            board[c][i] = 0;
            visitRow[i] = false;
        }
    }
}

int main(void) {
    scanf("%d", &N);
    dfs(0);
    printf("%d", cnt);
    
    return 0;
}


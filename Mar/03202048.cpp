#include <cstdio>
#include <algorithm>
#define MAX 22
using namespace std;

int N;
int maxNum;
int board[MAX][MAX];

void moveLeft();
void moveRight();
void moveUp();
void moveDown();

int findBiggestNum() {
    int maxnum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] > maxnum) {
                maxnum = board[i][j];
            }
        }
    }
    return maxnum;
}

void orderMove(int dir) {
    if (dir == 0)
        moveLeft();
    if (dir == 1)
        moveRight();
    if (dir == 2)
        moveUp();
    if (dir == 3)
        moveDown();
}

void dfs(int cnt) {
    if (cnt == 5) {
        int num = findBiggestNum();
        if (maxNum < num) maxNum = num;
        return;
    }


    int backupBoard[MAX][MAX];
    copy(&board[0][0], &board[0][0] + MAX*MAX, &backupBoard[0][0]);
    for (int i = 0; i < 4; i++) {
        orderMove(i);
        dfs(cnt+1);
        copy(&backupBoard[0][0], &backupBoard[0][0] + MAX*MAX, &board[0][0]);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    dfs(0);

    printf("%d", maxNum);
    return 0;
}


void moveLeft() {
    for (int i = 0; i < N; i++) {
        bool isCombined = false;
        for (int j = 0; j < N; j++) {
            int nj = j;
            while (nj > 0 && board[i][nj - 1] == 0) nj--;
            if (nj != j) {
                board[i][nj] = board[i][j];
                board[i][j] = 0;
            }

            if (!isCombined && nj > 0 && board[i][nj] == board[i][nj - 1]) {
                board[i][nj - 1] *= 2;
                board[i][nj] = 0;
                isCombined = true;
            } else if (board[i][nj] != 0) {
                isCombined = false;
            }
        }
    }
}

void moveRight() {
    for (int i = 0; i < N; i++) {
        bool isCombined = false;
        for (int j = N-1; j >= 0; j--) {
            int nj = j;
            while (nj < N-1 && board[i][nj + 1] == 0) nj++;
            if (nj != j) {
                board[i][nj] = board[i][j];
                board[i][j] = 0;
            }

            if (!isCombined && nj < N-1 && board[i][nj] == board[i][nj + 1]) {
                board[i][nj + 1] *= 2;
                board[i][nj] = 0;
                isCombined = true;
            } else if (board[i][nj] != 0) {
                isCombined = false;
            }
        }
    }
}

void moveUp() {
    for (int j = 0; j < N; j++) {
        bool isCombined = false;
        for (int i = 0; i < N; i++) {
            int ni = i;
            while (ni > 0 && board[ni-1][j] == 0) ni--;
            if (ni != i) {
                board[ni][j] = board[i][j];
                board[i][j] = 0;
            }

            if (!isCombined && ni > 0 && board[ni][j] == board[ni-1][j]) {
                board[ni - 1][j] *= 2;
                board[ni][j] = 0;
                isCombined = true;
            } else if (board[ni][j] != 0) {
                isCombined = false;
            }
        }
    }
}

void moveDown() {
    for (int j = 0; j < N; j++) {
        bool isCombined = false;
        for (int i = N-1; i >= 0; i--) {
            int ni = i;
            while (ni < N-1 && board[ni+1][j] == 0) ni++;
            if (ni != i) {
                board[ni][j] = board[i][j];
                board[i][j] = 0;
            }

            if (!isCombined && ni < N-1 && board[ni][j] == board[ni+1][j]) {
                board[ni + 1][j] *= 2;
                board[ni][j] = 0;
                isCombined = true;
            } else if (board[ni][j] != 0) {
                isCombined = false;
            }
        }
    }
}

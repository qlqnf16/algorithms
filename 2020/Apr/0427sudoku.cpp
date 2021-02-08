#include <stdio.h>

int sudoku[9][9];
int checkHori[9][10];
int checkVert[9][10];
int checkSquare[3][3][10];
int emptyCnt;
struct POS {
    int c, r;
};
POS empty[9*9];

int dfs(int n) {
    if (n >= emptyCnt) return 1;
    int c = empty[n].c;
    int r = empty[n].r;
    
    for (int i = 1; i <= 9; i++) {
        if (checkVert[c][i] || checkHori[r][i] || checkSquare[c/3][r/3][i]) continue;
        checkVert[c][i] = checkHori[r][i] = checkSquare[c/3][r/3][i] = 1;
        sudoku[c][r] = i;
        if (dfs(n+1)) return 1;
        checkVert[c][i] = checkHori[r][i] = checkSquare[c/3][r/3][i] = 0;
    }
    
    return 0;
}

void outputData() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!sudoku[i][j]) {
                empty[emptyCnt].c = i;
                empty[emptyCnt].r = j;
                emptyCnt++;
            } else {
                int k = sudoku[i][j];
                checkVert[i][k] = checkHori[j][k] = checkSquare[i/3][j/3][k] = 1;
            }
        }
    }
    dfs(0);
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    solve();
    outputData();
}

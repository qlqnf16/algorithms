#include <cstdio>
#define MAX 100
using namespace std;

int N;
int board[MAX][MAX];

void colorPaper(int c, int r) {
    for (int i = c; i < c + 10; i++) {
        for (int j = r; j < r + 10; j++) {
            if (!board[i][j]) board[i][j] = 1;
        }
    }
}

int findBiggestSquare(int c, int r) {
    int nc = c, nr = r, sqr = 0, max = 0, minr = 98798;
    while (nc < MAX && board[nc][nr]) {
        while (nr < MAX && board[nc][nr]) {
            nr++;
            if (nr >= minr) break;
        }
        if (nr < minr) minr = nr;
        sqr = (nc + 1 - c) * (minr - r);
        if (sqr > max) {
            max = sqr;
        }
        nc++;
        nr = r;
    }

    return max;
}

int solve() {
    int max = 0, sqr;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (board[i][j]) {
                sqr = findBiggestSquare(i, j);
                if (sqr > max) max = sqr;
            }
        }
    }
    return max;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int c, r;
        scanf("%d %d", &r, &c);
        colorPaper(90-c, r);
    }
    int ans = solve();
    printf("%d", ans);

    return 0;
}

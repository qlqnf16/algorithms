#include <stdio.h>
#define MAX 1000

int N;
int land[MAX+10][MAX+10];
int startPos[MAX];
int endPos[MAX];

void checkLand(int c, int r) {
    for (int i = c; i < c + 100; i++) {
        if (r < startPos[i]) startPos[i] = r;
        if (r + 100 > endPos[i]) endPos[i] = r;
        for (int j = r; j < r + 100; j++) {
            land[i][j] = 1;
        }
    }
}

void countHeight() {
    for (int i = 1; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (!land[i][j]) continue;
            land[i][j] += land[i-1][j];
        }
    }
}

int findMaxWidth() {
    int curheight, maxArea = 100*100, area;
    for (int i = 1; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            curheight = 1000;
            for (int k = j; k < MAX; k++) {
                if (land[i][k] < curheight) curheight = land[i][k];
                if (!curheight) break;
                area = curheight * (k-j+1);
                if (area > maxArea) maxArea = area;
            }
        }
    }
    return maxArea;
}

void solve() {
    int ans;
    countHeight();
    ans = findMaxWidth();
    printf("%d", ans);
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int c, r;
        scanf("%d %d", &c, &r);
        checkLand(c, r);
    }
    solve();
    return 0;
}

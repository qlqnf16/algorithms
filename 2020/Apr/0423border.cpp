#include <stdio.h>
#define MAX 100

int N;
char map[MAX+2][MAX+2];
int border;
int dc[] = {0, 0, 1, -1};
int dr[] = {1, -1, 0, 0};

void floodFill(int c, int r) {
    if (map[c][r] != '0') {
        if (map[c][r] == '1') {
            border++;
        }
        return;
    }
    map[c][r] = '2';
    for (int i =0; i< 4 ; i++) {
        floodFill(c+dc[i], r+dr[i]);
    }
}

int solve() {
    int ans;
    floodFill(0, MAX+1);
    floodFill(MAX+1, 0);
    floodFill(0, 0);
    floodFill(MAX+1, MAX+1);
    ans = border;
    return ans;
}

void initialize() {
    for (int i = 0; i <= MAX+1; i++) {
        for (int j = 0; j <= MAX+1; j++) {
            map[i][j] = '0';
        }
    }
}

int main() {
    int ans;
    initialize();
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int c, r;
        scanf("%d %d", &r, &c);
        map[c][r] = '1';
    }
    ans = solve();
    printf("%d", ans);
    return 0;
}


#include <stdio.h>
#define MAX 500
#define INF (int(1e9))

int N, goal, ans, check;
int map[MAX+10][MAX+10];
int visit[MAX+10][MAX+10];
int dir[][4] = {{0, 0, -1, 1}, {1, -1, 0, 0}};
int s = INF, e;

int abs(int n) {
    return n < 0 ? -n : n;
}

void floodFill(int c, int r, int p) {
    int nc, nr;
    if (check >= goal) return;
    visit[c][r] = true;
    check ++;
    
    for (int i = 0; i < 4; i++) {
        nc = c + dir[0][i];
        nr = r + dir[1][i];
        if (nc < 0 || nc >= N || nr < 0 || nr >= N) continue;
        if (abs(map[nc][nr] - map[c][r]) > p) continue;
        if (visit[nc][nr]) continue;
        floodFill(nc, nr, p);
    }
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visit[i][j] = false;
        }
    }
}

bool isPossiblePower(int p) {
    init();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            check = 0;
            floodFill(i, j, p);
            if (check >= goal) return true;
        }
    }
    return false;
}

void solve() {
    int m;
    goal = N % 2 ? (N*N+1)/2 : (N*N)/2;
    while (s <= e) {
        m = (s+e)/2;
        if (isPossiblePower(m)) {
            ans = m;
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
}

int main() {
    int in;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &in);
            map[i][j] = in;
            if (in < s) s = in;
            if (in > e) e = in;
        }
    }
    solve();
    printf("%d", ans);
}

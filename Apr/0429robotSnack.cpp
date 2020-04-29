#include <stdio.h>
#include <queue>
#define MAXM 110
#define MAXR 12
using namespace std;

struct POS {
    int c, r, d;
};
int N, minDist;
int map[MAXM+2][MAXM+2];
int visit[MAXM+2][MAXM+2];
POS snacks[MAXR];
POS robots[MAXR];
int dist[MAXR][MAXR];
bool checkSnaks[MAXR];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &snacks[i].c, &snacks[i].r);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &robots[i].c, &robots[i].r);
    }
}

void bfs(int c, int r, int u) {
    int nc, nr, found = 0;
    queue<POS> posQueue;
    posQueue.push({c, r, 0});
    visit[c][r] = u;
    
    while (!posQueue.empty()) {
        POS cur = posQueue.front();
        posQueue.pop();
        for (int i = 0; i < N; i++) {
            if (cur.c == snacks[i].c && cur.r == snacks[i].r) {
                found++;
                dist[u][i] = cur.d;
            }
        }
        if (found == N) return;
        
        for (int i = 0; i < 4; i++) {
            nc = cur.c + dir[0][i];
            nr = cur.r + dir[1][i];
            if (nc < 0 || nc > MAXM || nr < 0 || nr > MAXM) continue;
            if (visit[nc][nr] == u) continue;
            visit[nc][nr] = u;
            posQueue.push({nc, nr, cur.d+1});
        }
    }
}

void calcMinDist() {
    for (int i = 0; i < N; i++) {
        bfs(robots[i].c, robots[i].r, i);
    }
}

void dfs(int n, int sum) {
    if (n >= N) {
        if (sum < minDist) minDist = sum;
        return;
    }
    if (sum > minDist) return;
    
    for (int i = 0; i < N; i++) {
        if (checkSnaks[i]) continue;
        checkSnaks[i] = true;
        dfs(n+1, sum + dist[n][i]);
        checkSnaks[i] = false;
    }
}

void initialize() {
    minDist = 987987;
    for (int i = 0; i < MAXM; i++) {
        for (int j = 0; j < MAXM; j++) {
            visit[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        checkSnaks[i] = false;
        for (int j = 0; j < N; j++) {
            dist[i][j] = -1;
        }
    }
}

void solve() {
    initialize();
    calcMinDist();
    dfs(0, 0);
    printf("%d\n", minDist);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        input();
        solve();
    }
    
    return 0;
}

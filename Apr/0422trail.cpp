#include <stdio.h>
#define MAX 102
#define INF 987987987
#define MAXQ (MAX * MAX * 10)

int N;
int tc, tr;
int map[MAX][MAX];
int visit[MAX][MAX];

struct q {
    int c, r;
};
q que[MAXQ];
int wp, rp, qsize;

bool empty();
q front();
void pop();
void push(int c, int r, int t);

int sqr(int n) {
    return n * n;
}

void initialize() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visit[i][j] = INF;
        }
    }
}

void bfs(int c, int r) {
    int nc, nr, nt;
    int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
    push(tc, tr, 0);
    
    while (!empty()) {
        q cur = front();
        pop();
        for (int i = 0; i < 4; i++) {
            nc = cur.c + dir[0][i];
            nr = cur.r + dir[1][i];
            
            if (nc <= 0 || nc > N || nr <= 0 || nr > N) continue;
            if (map[nc][nr] > map[cur.c][cur.r]) {
                nt = visit[cur.c][cur.r] + map[nc][nr] - map[cur.c][cur.r];
            }
            else if (map[nc][nr] < map[cur.c][cur.r]) {
                nt = visit[cur.c][cur.r] + sqr(map[cur.c][cur.r] - map[nc][nr]);
            }
            else {
                nt = visit[cur.c][cur.r];
            }
            push(nc, nr, nt);
        }
    }
}

int findLeastPower() {
    int min = INF, pow = 0;
    for (int i = 1; i <= N; i++) {
        pow = visit[i][1] + sqr(map[i][1]);
        if (pow < min) min = pow;
        pow = visit[i][N] + sqr(map[i][N]);
        if (pow < min) min = pow;
    }
    for (int j = 2; j < N; j++) {
        pow = visit[1][j] + sqr(map[1][j]);
        if (pow < min) min = pow;
        pow = visit[N][j] + sqr(map[N][j]);
        if (pow < min) min = pow;
    }
    return min;
}

void solve() {
    int ans;
    initialize();
    bfs(tc, tr);
    ans = findLeastPower();
    printf("%d", ans);
}

int main() {
    scanf("%d", &N);
    scanf("%d %d", &tc, &tr);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    solve();
    return 0;
}

bool empty() {
    return qsize == 0;
}

q front() {
    return que[rp];
}


void pop() {
    rp = (rp+1) % MAXQ;
    qsize--;
}

void push(int c, int r, int t) {
    if (visit[c][r] <= t) return;
    visit[c][r] = t;
    que[wp].c = c; que[wp].r = r;
    wp = (wp+1) % MAXQ;
    qsize++;
}

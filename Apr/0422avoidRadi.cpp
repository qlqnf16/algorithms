#include <stdio.h>
#define MAX 102
#define INF (10*100*100)
#define MAXQ (MAX * MAX * 10) //linear queue 일때는 *50~*100 정도 필요

int N;
int map[MAX][MAX];
int visit[MAX][MAX];

struct queue {
    int c, r, t;
};
queue que[MAXQ]; //circular queue
int wp, rp, qsize;

bool empty() {
    return qsize == 0;
}

queue front() {
    return que[rp];
}

queue back() {
    if (wp) return que[wp-1];
    return que[MAXQ-1];
}

void pop() {
    rp = (rp+1) % MAXQ;
    qsize--;
}

void push(int c, int r, int t) {
    if(visit[c][r] <= t) return;
    visit[c][r] = t;
    que[wp].c = c; que[wp].r = r;
    wp = (wp+1) % MAXQ;
    qsize++;
}

int bfs() {
    int nc,nr;
    int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
    push(0, 0, 0);
    
    while (!empty()) {
        queue cur = front();
        pop();
        for (int i = 0; i < 4; i++) {
            nc = cur.c + dir[0][i];
            nr = cur.r + dir[1][i];
            push(nc, nr, visit[cur.c][cur.r] + map[nc][nr]);
        }
    }
    
    return visit[N-1][N-1];
}

void initialize() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visit[i][j] = INF;
        }
    }
}

int main() {
    int ans;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    initialize();
    ans = bfs();
    printf("%d", ans);
    return 0;
}

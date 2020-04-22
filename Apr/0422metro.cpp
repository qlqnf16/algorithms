#include <stdio.h>
#define MAX 102
#define INF (6*100)
#define MAXQ (MAX * MAX * 10)
int N, M;
int costs[MAX][MAX];

struct record {
    int t;
    int prev;
    int i;
};
record visit[MAX];

int que[MAXQ];
int wp, rp, qsize;

bool empty();
int front();
void pop();
void push(int n, int p, int t);

record bfs() {
    wp = rp = 0;
    push(1, 0, 0);
    
    while (!empty()) {
        int cur = front();
        pop();
        
        for (int i = 1; i <= N; i++) {
            if (i == cur) continue;
            push(i, cur, visit[cur].t+costs[cur][i]);
        }
    }
    
    return visit[M];
}

void initialize() {
    for (int i = 1; i <= N; i++) {
        visit[i].t = INF;
    }
    
}

void solve() {
    record ans, temp;
    int route[MAX];
    int routeidx = 0;
    
    initialize();
    ans = bfs();
    
    temp = ans;
    while (temp.i) {
        route[routeidx] = temp.i;
        routeidx++;
        temp = visit[temp.prev];
    }
    
    printf("%d\n", ans.t);
    for (int i = routeidx-1; i >= 0; i--) {
        printf("%d ", route[i]);
    }
}

int main() {
    record ans;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &costs[i][j]);
        }
    }
    solve();

    return 0;
}

bool empty() {
    return qsize == 0;
}

int front() {
    return que[rp];
}


void pop() {
    rp = (rp+1) % MAXQ;
    qsize--;
}

void push(int n, int p, int t) {
    if (visit[n].t <= t) return;
    visit[n].t = t;
    visit[n].prev = p;
    visit[n].i = n;
    
    que[wp] = n;
    wp = (wp+1) % MAXQ;
    qsize++;
}

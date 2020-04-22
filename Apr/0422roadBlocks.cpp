#include <stdio.h>
#define MAX 102
#define INF (1000000 * 105)
#define MAXQ (MAX * MAX * 10) //linear queue 일때는 *50~*100 정도 필요

int N, M;
int roads[MAX][MAX];
int path[MAX];
int visit[MAX];
int newRoute;

int que[MAXQ]; //circular queue
int wp, rp, qsize;

bool empty();
int front();
void pop();
void push(int n, int p, int t);

int bfs() {
    wp = rp = qsize = 0;
    push(1, 0, 0);
    
    while (!empty()) {
        int cur = front();
        pop();
        for (int i = 1; i <= N; i++) {
            if (cur == i || !roads[cur][i]) continue;
            push(i, cur, visit[cur] + roads[cur][i]);
        }
    }
    
    return visit[N];
}

void initialize() {
    for (int i = 0; i <= N; i++) {
        visit[i] = INF;
    }
}

void stretchRoads(int n) {
    int prev = path[n], temp;
    if (!prev) {
        return;
    }
    
    initialize();
    roads[n][prev] = roads[prev][n] *= 2;
    temp = bfs();
    if (temp > newRoute) newRoute = temp;
    roads[n][prev] = roads[prev][n] /= 2;
    stretchRoads(prev);
}

void solve() {
    int preAns;
    initialize();
    preAns = bfs();
    stretchRoads(N);
    printf("%d", newRoute - preAns);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        roads[a][b] = roads[b][a] = l;
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
    if (visit[n] <= t) return;
    visit[n] = t;
    path[n] = p;
    que[wp] = n;
    wp = (wp+1) % MAXQ;
    qsize++;
}

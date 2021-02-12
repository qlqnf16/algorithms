#include <stdio.h>
#define MAX 55
#define INF (MAX * MAX * MAX)
#define MAXQ (MAX * MAX * 10)

int C, R;
int sc, sr, ec, er;
char map[MAX][MAX];
int flood[MAX][MAX];
bool visit[MAX][MAX];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

struct q {
    int c, r, t;
};
q que[MAXQ];
int wp, rp, qsize;

bool empty();
q front();
void pop();
void pushFlood(int, int, int);
void pushPainter(int, int, int);

void findFlood() {
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= R; j++) {
            if (map[i][j] == '*') {
                pushFlood(i, j, 0);
                map[i][j] = '.';
            }
            if (map[i][j] == 'S') {
                sc = i; sr = j;
            }
            if (map[i][j] == 'D') {
                ec = i; er = j;
            }
            if (map[i][j] == 'X') flood[i][j] = -1;
        }
    }
}

void floodBfs() {
    int nc, nr;
    while (!empty()) {
        q cur = front();
        pop();
        
        for (int i = 0; i < 4; i++) {
            nc = cur.c + dir[0][i];
            nr = cur.r + dir[1][i];
            if (nc < 1 || nc > C || nr < 1 || nr > R) continue;
            pushFlood(nc, nr, cur.t+1);
        }
    }
}

int painterBfs() {
    int nc, nr;
    wp = rp = 0;
    pushPainter(sc, sr, 0);
    
    while (!empty()) {
        q cur = front();
        pop();
        
        if (cur.c == ec && cur.r == er) return cur.t;
        
        for (int i = 0; i < 4; i++) {
            nc = cur.c + dir[0][i];
            nr = cur.r + dir[1][i];
            if (nc < 1 || nc > C || nr < 1 || nr > R) continue;
            pushPainter(nc, nr, cur.t+1);
        }
    }

    return -1;
}

void initialize() {
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= R; j++) {
            flood[i][j] = INF;
            visit[i][j] = false;
        }
    }
}

void solve() {
    int ans;
    initialize();
    findFlood();
    floodBfs();
    ans = painterBfs();
    if (ans == -1) printf("KAKTUS\n");
    else printf("%d\n", ans);
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &C, &R);
        for (int i = 1; i <= C; i++) {
            scanf("%s", &map[i][1]);
        }
        solve();
    }
    
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

void pushFlood(int c, int r, int t) {
    if (map[c][r] == 'D' || map[c][r] == 'X' || map[c][r] == 'S') return;
    if (flood[c][r] <= t) return;
    flood[c][r] = t;
    que[wp].c = c; que[wp].r = r; que[wp].t = t;
    wp = (wp+1) % MAXQ;
    qsize++;
}

void pushPainter(int c, int r, int t) {
    if (visit[c][r]) return;
    if (map[c][r] == 'X') return;
    if (flood[c][r] <= t) return;
    visit[c][r] = true;
    que[wp].c = c; que[wp].r = r; que[wp].t = t;
    wp = (wp+1) % MAXQ;
    qsize++;
}

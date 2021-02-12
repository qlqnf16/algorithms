#include <stdio.h>
#define MAX 20

int C, R;
char board[MAX][MAX];
bool visit[MAX][MAX][MAX][MAX];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

struct queue {
    int cred;
    int rred;
    int cblue;
    int rblue;
    int t;
};
queue que[MAX*MAX*MAX*MAX];
int wp, rp;

void pop() {rp++;}

queue front() { return que[rp]; }

int empty() { return wp == rp; }

void push(int cred, int rred, int cblue, int rblue, int t, int d) {
    if (board[cred][rred] == '#' && board[cblue][rblue] == '#') return;
    if (board[cred][rred] == '#') {
        cred -= dir[0][d];
        rred -= dir[1][d];
    }
    if (board[cblue][rblue] == '#') {
        cblue -= dir[0][d];
        rblue -= dir[1][d];
    }
    
    if (visit[cred][rred][cblue][rblue]) return;
    if (cred == cblue && rred == rblue) return;
    if (board[cblue][rblue] == 'H') return;
    
    visit[cred][rred][cblue][rblue] = true;
    que[wp].cred = cred; que[wp].rred = rred;
    que[wp].cblue = cblue; que[wp].rblue = rblue; que[wp].t = t;
    wp++;
}

void findBeads() {
    int cr, rr, cb, rb;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            if (board[i][j] == 'R') {
                cr = i;
                rr = j;
            }
            if (board[i][j] == 'B') {
                cb = i;
                rb = j;
            }
        }
    }
    push(cr, rr, cb, rb, 0, 0);
}

int solve() {
    queue cur;
    int ncred, nrred, ncblue, nrblue;
    wp = rp = 0;
    findBeads();
    
    while (!empty()) {
        cur = front();
        printf("%d %d %d %d %d\n", cur.cred, cur.rred, cur.cblue, cur.rblue, cur.t);
        pop();
        if (cur.t > 10) return -1;
        if (board[cur.cred][cur.rred] == 'H') return cur.t;
        for (int i = 0; i < 4; i++) {
            ncred = cur.cred + dir[0][i];
            nrred = cur.rred + dir[1][i];
            ncblue = cur.cblue + dir[0][i];
            nrblue = cur.rblue + dir[1][i];
            push(ncred, nrred, ncblue, nrblue, cur.t + 1, i);
        }
    }
    return -1;
}

void initiate() {
    for (int i = 0; i < C; i++) {
        for (int j= 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                for (int l = 0; l < R; l++) {
                    visit[i][j][k][l] = false;
                }
            }
        }
    }
}

int main() {
    int T, ans;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &C, &R);
        for (int i = 0; i < C; i++) {
            scanf("%s", board[i]);
        }
        ans = solve();
        printf("%d\n", ans);
        initiate();
    }
    
    return 0;
}

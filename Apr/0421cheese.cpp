#include <stdio.h>
#define MAX 1010

int H, W, N;
char map[MAX][MAX];
int visit[MAX][MAX];

int cheeseLocs[10][2];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

struct queue {
    int c;
    int r;
    int t;
};
queue que[MAX*MAX];
int wp, rp;

void pop() {rp++;}

queue front() { return que[rp]; }

int empty() { return wp == rp; }

void push(int c, int r, int t, int n) {
    if (visit[c][r] > n) return;
    if (map[c][r] != '.') return;
    visit[c][r] ++;
    que[wp].c = c; que[wp].r = r; que[wp].t = t;
    wp ++;
}

void preAct() {
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (map[i][j] == 'S') {
                cheeseLocs[0][0] = i;
                cheeseLocs[0][1] = j;
                map[i][j] = '.';
            }
            if (map[i][j] <= '9' && map[i][j] >= '1') {
                cheeseLocs[map[i][j]-'0'][0] = i;
                cheeseLocs[map[i][j]-'0'][1] = j;
                map[i][j] = '.';
            }
        }
    }
}

int bfs(int c, int r, int n) {
    wp = rp = 0;
    push(c, r, 0, n);
    
    while (!empty()) {
        queue cur = front();
        pop();
        if (cur.c == cheeseLocs[n+1][0] && cur.r == cheeseLocs[n+1][1]) return cur.t;
        
        for (int i = 0; i < 4; i++) {
            push(cur.c + dir[0][i], cur.r + dir[1][i], cur.t+1, n);
        }
    }
    
    return -1;
}

int solve() {
    int route = 0;
    preAct();
    for (int i = 0; i < N; i++) {
        route += bfs(cheeseLocs[i][0], cheeseLocs[i][1], i);
    }
    return route;
}

int main() {
    int ans;
    scanf("%d %d %d", &H, &W, &N);
    for (int i = 1; i <= H; i++) {
        scanf("%s", &map[i][1]);
    }
    ans = solve();
    printf("%d", ans);
    
    return 0;
}

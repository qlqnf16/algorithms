#include <stdio.h>
#define MAX 1010

int H, W;
char map[MAX][MAX];
int depth[MAX][MAX];
int wave[MAX][MAX];
bool visit[MAX][MAX];
int dir[][8] = {{0, 0, 1, -1, -1, -1, 1, 1}, {1, -1, 0, 0, -1, 1, 1, -1}};

struct queue {
    int c;
    int r;
    int sec;
};
queue que[MAX*MAX];
int wp, rp;

void pop() {rp++;}

queue front() { return que[rp]; }

int empty() { return wp == rp; }

void push(int c, int r, int sec) {
    if (map[c][r] >= '9' || map[c][r] < '0') return;
    if (visit[c][r]) return;
    que[wp].c = c; que[wp].r = r; que[wp].sec = sec;
    wp++;
    visit[c][r] = true;
}

bool willDestroy(int c, int r) {
    if (map[c][r] == '.') return false;
    int num = map[c][r] - '0';
    int count = 0;
    for (int i = 0; i < 8 ; i++) {
        if (map[c+dir[0][i]][r+dir[1][i]] == '.') {
            count ++;
            wave[c][r] ++;
        }
    }
    if (count >= num) return true;
    return false;
}


int bfs(int c, int r) {
    int nc,nr,cnt = 0;
    push(c, r, 1);
    queue cur;
    while (!empty()) {
        cur = front();
        cnt = 0;
        pop();
        
        for (int i = 0; i < 8; i++) {
            nc = cur.c + dir[0][i];
            nr = cur.r + dir[1][i];
            if (map[nc][nr] != '.' && depth[nc][nr] < cur.sec) cnt++;
            push(nc, nr, cur.sec+1);
        }
        
        if (cnt >= map[cur.c][cur.r]) {
            map[cur.c][cur.r] = '.';
            depth[cur.c][cur.r] = cur.sec;
        }
    }
    
    return cur.sec;
}

void solve() {
    int ans;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (map[i][j] != '.' && map[i][j] <= '9') {
                if (willDestroy(i, j)) {
                    push(i, j, 1);
                }
            }
        }
    }
    ans = bfs();
    printf("%d", ans);
}

int main() {
    scanf("%d %d", &H, &W);
    for (int i = 1; i <= H; i++) {
        scanf("%s", &map[i][1]);
    }
    solve();
    return 0;
}

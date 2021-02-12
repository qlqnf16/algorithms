#include <stdio.h>
#define MAX 4010

int H, W;
char map[MAX][MAX];
bool visit[MAX][MAX];

struct queue {
    int c;
    int r;
    int t;
};
queue que[MAX*MAX];
int wp, rp;

void pop() {
    rp++;
}

queue front() {
    return que[rp];
}

void push(int c, int r, int t) {
    if (map[c][r] != '.' && map[c][r] != 'G' & map[c][r] != 'S') return;
    if (visit[c][r]) return;
    que[wp].c = c; que[wp].r = r; que[wp].t = t;
    wp++;
    visit[c][r] = true;
}

int empty() {
    return wp == rp;
}


int bfs(int c, int r) {
    int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
    wp = rp = 0;
    push(c, r, 0);
    
    while (!empty()) {
        queue cur = front();
        pop();
        if (map[cur.c][cur.r] == 'G') return cur.t;
        
        for (int i = 0; i < 4; i++) {
            push(cur.c+dir[0][i], cur.r+dir[1][i], cur.t+1);
        }
    }
    
    return -1;
}

int main() {
    int ans;
    scanf("%d %d", &H, &W);
    for (int i = 1; i <= H; i++) {
        scanf("%s", &map[i][1]);
    }
    
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (map[i][j] == 'S') ans = bfs(i, j);
        }
    }
    printf("%d", ans);
    return 0;
}

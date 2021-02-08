#include <cstdio>
#include <vector>
#define MAXB 12
#define MAXP 11
using namespace std;

int N, K;
int board[MAXB+2][MAXB+2];
int visit[MAXB+2][MAXB+2];
int dir[][5] = {{0, 0, 0, -1, 1}, {0, 1, -1, 0, 0}}; //-우좌상하
typedef struct {
    int c, r, d, td;
    int bottom, top;
    int pinsInGroup;
    bool isOnBack;
} POS;
POS pins[MAXP];
int back[MAXP][MAXP];

void input();

void reversePinTower(int pid) {
    int temp, td;
    temp = pins[pid].bottom;
    td = pins[pid].d;
    
    pins[pid].bottom = pins[pid].top;
    pins[pid].top = temp;
    pins[pid].d = pins[pid].td;
    pins[pid].td = td;
}

void stackPin(int p, int np) {
    pins[p].isOnBack = true;
    pins[np].top = pins[p].top;
    pins[np].td = pins[p].td;
    pins[np].pinsInGroup += pins[p].pinsInGroup;
    
//    pins[p].isOnBack = true;
//    back[np][pins[np].pinsOnBack] = p;
//    pins[np].pinsOnBack++;
//    if (pins[p].pinsOnBack) {
//        for (int i = 0; i < pins[p].pinsOnBack; i++) {
//            back[np][pins[np].pinsOnBack] = back[p][i];
//            pins[np].pinsOnBack++;
//        }
//    }
}

int movePin(int pid) {
    int c, r, d, nc, nr, np;
    c = pins[pid].c;
    r = pins[pid].r;
    d = pins[pid].d;
    nc = c + dir[0][d];
    nr = r + dir[1][d];
    
    if (nc < 1 || nc > N || nr < 1 || nr > N || board[nc][nr] == 2) {
        d = d % 2 ? d + 1 : d - 1;
        nc = c + dir[0][d];
        nr = r + dir[1][d];
        pins[pid].d = d;
        if (board[nc][nr] == 2) return 1;
    }
    if (nc < 1 || nc > N || nr < 1 || nr > N || board[nc][nr] == 1) reversePinTower(pid);
    
    printf("%d %d %d => %d %d\n", d, c, r, nc, nr);
    if (visit[nc][nr]) {
        np = visit[nc][nr];
        if (pins[np].pinsInGroup + pins[pid].pinsInGroup >= 4) return -1;
        stackPin(pid, np);
    } else {
        visit[nc][nr] = pid;
    }
    visit[c][r] = 0;
    pins[pid].c = nc;
    pins[pid].r = nr;
    
    return 0;
}

void debugger(int t, int p) {
    printf("%d번째 턴 %d번 말\n", t, p);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
    printf("\n");
//    for (int i = 1; i <= K; i++) {
//        printf("[%d][%d] - Top%d Bot%d %s\n", pins[i].c, pins[i].r, pins[i].top, pins[i].bottom, pins[i].isOnBack ? "업힘" : "");
//    }
//    printf("\n");
}

int solve() {
    int turn, isStucked, tempRes;
    for (turn = 1; turn <= 1000; turn++) {
        isStucked = 0;
        for (int p = 1; p <= K; p++) {
            if (pins[p].isOnBack) continue;
            tempRes = movePin(p);
            debugger(turn, p);
            if (tempRes == -1) return turn;
            isStucked += tempRes;
        }
        if (isStucked == K) return -1;
    }
    
    return -1;
}

int main() {
    int ans;
    input();
    ans = solve();
    printf("%d", ans);
    
    return 0;
}


void input() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    for (int i = 1; i <= K; i++) {
        scanf("%d %d %d", &pins[i].c, &pins[i].r, &pins[i].d);
        visit[pins[i].c][pins[i].r] = i;
        pins[i].isOnBack = false;
        pins[i].bottom = pins[i].top = i;
        pins[i].td = pins[i].d;
        pins[i].pinsInGroup = 1;
    }
}

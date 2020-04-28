#include <stdio.h>
#define MAX 110

struct MOVE {
    int sec;
    char dir;
};
struct SNK {
    int h, t;
    int leng;
    int dir;
} snake = {0, 0, 1, 0};
int N, K, L;
int board[MAX][MAX];
int route[MAX*MAX][2];
MOVE moves[MAX];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
int turn[][2] = {{2, 3}, {3, 2}, {1, 0}, {0, 1}};

void input() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++) {
        int c, r;
        scanf("%d %d", &c, &r);
        board[c][r] = 1;
    }
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        scanf(" %d %c", &moves[i].sec, &moves[i].dir);
    }
}

int moveSnake() {
    int hc, hr, nhc, nhr, tc, tr;
    hc = route[snake.h][0];
    hr = route[snake.h][1];
    nhc = hc + dir[0][snake.dir];
    nhr = hr + dir[1][snake.dir];
    tc = route[snake.t][0];
    tr = route[snake.t][1];
    
    if (nhc <= 0 || nhc > N || nhr <= 0 || nhr > N) return 0;
    if (board[nhc][nhr] == 2) return 0;
    if (board[nhc][nhr] == 1) {
        snake.h += 1;
    } else {
        board[tc][tr] = 0;
        snake.t ++;
        snake.h ++;
    }
    route[snake.h][0] = nhc;
    route[snake.h][1] = nhr;
    board[nhc][nhr] = 2;
    
    return 1;
}

int solve() {
    int t, mi = 0;
    board[1][1] = 2;
    route[0][0] = route[0][1] = 1;
    
    for (t = 0;; t++) {
        if (mi >= L) break;
        if (moves[mi].sec == t) {
            if (moves[mi].dir == 'D') snake.dir = turn[snake.dir][0];
            else snake.dir = turn[snake.dir][1];
            mi++;
        }
        if (!moveSnake()) return t+1;
    }
    
    return t-1;
}

int main() {
    int ans;
    input();
    ans = solve();
    printf("%d", ans);
    
    return 0;
}


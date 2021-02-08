#include <cstdio>
#include <queue>
#define MAX 110
using namespace std;

typedef struct st {
    int height;
    int col;
    int row;
} position;
int C, R, H;
int map[MAX][MAX][MAX];
int route[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int dir[][6] = {{0, 0, 0, 0, 1, -1}, {0, 0, 1, -1, 0, 0}, {1, -1, 0, 0, 0, 0}};
int maxx;

queue<position> posQueue;

void bfs() {
    int h, c, r, nh, nc, nr;
    while (!posQueue.empty()) {
        h = posQueue.front().height;
        c = posQueue.front().col;
        r = posQueue.front().row;
        posQueue.pop();
        
        for (int i = 0; i < 6; i++) {
            nh = h + dir[0][i];
            nc = c + dir[1][i];
            nr = r + dir[2][i];
            if (nh < 0 || nh >= H || nc < 0 || nc >= C || nr < 0 || nr >= R) continue;
            if (!visit[nh][nc][nr] && map[nh][nc][nr] == 0) {
                visit[nh][nc][nr] = true;
                posQueue.push({nh, nc, nr});
                route[nh][nc][nr] = route[h][c][r] + 1;
            }
        }
    }
}

void initiate() {
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                map[h][i][j] = 0;
                visit[h][i][j] = false;
            }
        }
    }
}

int main() {
    bool unripe = false, ripe = false;
    scanf("%d %d %d", &R, &C, &H);
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                scanf("%d", &map[k][i][j]);
                if (unripe && ripe) continue;
                if (map[k][i][j]) ripe = true;
                else unripe = true;
            }
        }
    }
    
    if (!unripe) {
        printf("0");
        return 0;
    }
    if (!ripe) {
        printf("-1");
        return 0;
    }
    
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                if (map[k][i][j] == 1) {
                    posQueue.push({k, i, j});
                    visit[k][i][j] = true;
                }
            }
        }
    }
    bfs();
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                if (map[k][i][j] != -1 && !visit[k][i][j]) {
                    printf("-1");
                    return 0;
                }
                if (route[k][i][j] > maxx) maxx = route[k][i][j];
            }
        }
    }
    printf("%d", maxx);
    
    return 0;
}

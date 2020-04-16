#include <cstdio>
#include <queue>
#define MAX 1010
using namespace std;

int C, R;
int map[MAX][MAX];
int route[MAX][MAX];
bool visit[MAX][MAX];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
int maxx;

queue<int> colQueue;
queue<int> rowQueue;

void bfs() {
    int c, r, nc, nr;
    while (!colQueue.empty()) {
        c = colQueue.front();
        r = rowQueue.front();
        colQueue.pop();
        rowQueue.pop();
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            if (nc < 0 || nc >= C || nr < 0 || nr >= R) continue;
            if (!visit[nc][nr] && map[nc][nr] == 0) {
                visit[nc][nr] = true;
                colQueue.push(nc);
                rowQueue.push(nr);
                route[nc][nr] = route[c][r] + 1;
            }
        }
    }
}

void initiate() {
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            map[i][j] = 0;
            visit[i][j] = false;
        }
    }
}

int main() {
    bool unripe = false, ripe = false;
    scanf("%d %d", &R, &C);
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            scanf("%d", &map[i][j]);
            if (unripe && ripe) continue;
            if (map[i][j]) ripe = true;
            else unripe = true;
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
    
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            if (map[i][j] == 1) {
                colQueue.push(i);
                rowQueue.push(j);
                visit[i][j] = true;
            }
        }
    }
    bfs();
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            if (map[i][j] != -1 && !visit[i][j]) {
                printf("-1");
                return 0;
            }
            if (route[i][j] > maxx) maxx = route[i][j];
        }
    }
    printf("%d", maxx);
    
    return 0;
}

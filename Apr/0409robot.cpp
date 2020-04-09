#include <cstdio>
#include <queue>
#define MAX 101
using namespace std;

typedef struct st {
    int col;
    int row;
    int dir;
} position;

int C, R;
int map[MAX][MAX];
int route[MAX][MAX][MAX];
int dir[2][5] = {{0, 0, 0, 1, -1}, {0, 1, -1, 0, 0}}; //-동서남북
bool visit[MAX][MAX][5];
position start;
position goal;

bool isEqual(position a, position b) {
    if (a.col != b.col) return false;
    if (a.row != b.row) return false;
    if (a.dir != b.dir) return false;
    return true;
}

void bfs(position start) {
    int nc, nr, nd;
    position current;
    queue<position> posQueue;
    posQueue.push(start);
    visit[start.col][start.row][start.dir] = true;
    
    while (!posQueue.empty()) {
        current = posQueue.front();
        posQueue.pop();
        if (isEqual(current, goal)) return;
        
        for (int i = 1; i <= 3; i++) {
            nd = current.dir;
            nc = current.col + dir[0][nd] * i;
            nr = current.row + dir[1][nd] * i;
            
            if (nc <= 0 || nc > C || nr <= 0 || nr > R) break;
            if (map[nc][nr] == 1) break;
            if (!visit[nc][nr][nd]) {
                visit[nc][nr][nd] = true;
                route[nc][nr][nd] = route[current.col][current.row][current.dir] + 1;
                posQueue.push({nc, nr, nd});
            }
        }
        
        nc = current.col;
        nr = current.row;
        for (int i = 0; i < 2; i++) {
            if (current.dir < 3) nd = 3+i;
            else nd = 1+i;
            if (!visit[nc][nr][nd]) {
                visit[nc][nr][nd] = true;
                route[nc][nr][nd] = route[current.col][current.row][current.dir] + 1;
                posQueue.push({nc, nr, nd});
            }
        }
    }
}

int main(void) {
    scanf("%d %d", &C, &R);
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= R; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    scanf("%d %d %d", &start.col, &start.row, &start.dir);
    scanf("%d %d %d", &goal.col, &goal.row, &goal.dir);
    bfs(start);
    printf("%d", route[goal.col][goal.row][goal.dir]);
    return 0;
}

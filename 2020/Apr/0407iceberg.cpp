#include <cstdio>
#include <queue>
#define MAX 310
using namespace std;

int C, R, sol;
int map[MAX][MAX];
int near[MAX][MAX];
bool visit[MAX][MAX];
int dir[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};

void bfs(int c, int r) {
    int nc, nr;
    queue<int> colQueue;
    queue<int> rowQueue;
    
    colQueue.push(c);
    rowQueue.push(r);
    visit[c][r] = true;
    
    while (!colQueue.empty()) {
        c = colQueue.front();
        r = rowQueue.front();
        colQueue.pop();
        rowQueue.pop();
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            if (nc < 0 || nc >= C || nr < 0 || nr >= R) continue;
            if (!map[nc][nr]) near[c][r] += 1;
            if (!visit[nc][nr] && map[nc][nr]) {
                visit[nc][nr] = true;
                colQueue.push(nc);
                rowQueue.push(nr);
            }
        }
    }
}

void initVisit(void) {
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++){
            visit[i][j] = false;
            map[i][j] -= near[i][j];
            near[i][j] = 0;
            if (map[i][j] < 0) map[i][j] = 0;
        }
    }
}

void solve(void) {
    bool existIceberg;
    int group, t = 0;
    while (true) {
        group = 1;
        existIceberg = false;
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                if (map[i][j] && !visit[i][j]) {
                    if (group > 1) {
                        sol = t;
                        return;
                    }
                    bfs(i, j);
                    existIceberg = true;
                    group ++;
                }
            }
        }
        if (!existIceberg) return;
        t++;
        initVisit();
    }
}

int main(void) {
    scanf("%d %d", &C, &R);
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    solve();
    printf("%d", sol);
    
    return 0;
}

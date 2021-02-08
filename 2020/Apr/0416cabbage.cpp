#include <cstdio>
#include <queue>
#define MAX 55
using namespace std;

int C, R;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

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
            if (!visit[nc][nr] && map[nc][nr]) {
                visit[nc][nr] = true;
                colQueue.push(nc);
                rowQueue.push(nr);
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
    int T, worms, ans;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        ans = 0;
        scanf("%d %d %d", &R, &C, &worms);
        initiate();
        for (int i = 0; i < worms; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            map[y][x] = 1;
        }
        
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                if (map[i][j] && !visit[i][j]) {
                    bfs(i, j);
                    ans ++;
                }
            }
        }
        
        printf("%d\n", ans);
    }
    return 0;
}

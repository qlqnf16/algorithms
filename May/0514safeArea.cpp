#include <cstdio>
#include <queue>
#define MAX 105
using namespace std;

int N, minh = 110, maxh;
int land[MAX][MAX];
int visit[MAX][MAX];
int dir[][4] = {{0, 0, -1, 1}, {1, -1, 0, 0}};

void bfs(int r, int c, int u) {
    int nr, nc;
    queue<int> rowQueue;
    queue<int> colQueue;
    rowQueue.push(r);
    colQueue.push(c);
    visit[r][c] = u;
    
    while (!rowQueue.empty()) {
        r = rowQueue.front();
        c = colQueue.front();
        rowQueue.pop();
        colQueue.pop();
        
        for (int i = 0; i < 4; i++) {
            nr = r + dir[0][i];
            nc = c + dir[1][i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (visit[nr][nc] == u) continue;
            if (land[nr][nc] <= u) continue;
            visit[nr][nc] = u;
            rowQueue.push(nr);
            colQueue.push(nc);
        }
    }
}

int solve() {
    int maxLand = 1, cnt;
    for (int h = minh; h <= maxh; h++) {
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visit[i][j] == h || land[i][j] <= h) continue;
                cnt++;
                bfs(i, j, h);
            }
        }
        if (maxLand < cnt) maxLand = cnt;
    }
    return maxLand;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &land[i][j]);
            if (land[i][j] > maxh) maxh = land[i][j];
            if (land[i][j] < minh) minh = land[i][j];
        }
    }
    int ans = solve();
    printf("%d", ans);
    return 0;
}

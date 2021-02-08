#include <cstdio>
#include <queue>
#define MAX 1010
using namespace std;

int N, M;
int map[MAX][MAX];
int routeFromLeft[MAX][MAX];
int routeFromRight[MAX][MAX];
bool visit[MAX][MAX];

int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

void bfs(int c, int r, bool left) {
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
        
        if (map[c][r] == 1) continue;
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            
            if (nc < 0 || nc >= N || nr < 0 || nr >= M) continue;
            if (!visit[nc][nr]) {
                visit[nc][nr] = true;
                colQueue.push(nc);
                rowQueue.push(nr);
                if (left) routeFromLeft[nc][nr] = routeFromLeft[c][r] + 1;
                else routeFromRight[nc][nr] = routeFromRight[c][r] + 1;
            }
        }
    }
}

int findMinRoute() {
    int tempMin = 987987987;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!map[i][j]) continue;
            if (!routeFromLeft[i][j] || !routeFromRight[i][j]) continue;
            if (routeFromLeft[i][j] + routeFromRight[i][j] < tempMin) tempMin = routeFromLeft[i][j] + routeFromRight[i][j];
        }
    }
    return tempMin == 987987987 ? -1 : tempMin+1;
}

void initVisit() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visit[i][j] = false;
        }
    }
}

void solve(bool wall) {
    bfs(0, 0, true);
    if (wall) {
        initVisit();
        bfs(N-1, M-1, false);
        printf("%d", findMinRoute());
    } else {
        printf("%d", routeFromLeft[N-1][M-1] + 1);
    }
}

int main() {
    bool wall = false;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
            if (!wall && map[i][j] == 1) wall = true;
        }
    }
    solve(wall);
    
    return 0;
}

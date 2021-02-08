// 자외선 피하기

#include <cstdio>
#include <queue>
#define MAX 110
using namespace std;

int n;
int map[MAX][MAX];
int sumRoute[MAX][MAX];

int dir[2][4] = {{0,1,0,-1}, {1,0,-1,0}};

void bfs(int c, int r) {
    int nc, nr, temp;
    queue<int> colQueue;
    queue<int> rowQueue;
    
    colQueue.push(c);
    rowQueue.push(r);
    sumRoute[0][0] = map[0][0];
    
    while (!colQueue.empty()) {
        c = colQueue.front();
        r = rowQueue.front();
        colQueue.pop();
        rowQueue.pop();
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            
            if (nc >= 0 && nc < n && nr >= 0 && nr < n) {
                temp = map[nc][nr] + sumRoute[c][r];
                
                if (!sumRoute[nc][nr] || (sumRoute[nc][nr] > temp)) {
                    sumRoute[nc][nr] = temp;
                    colQueue.push(nc);
                    rowQueue.push(nr);
                }
            }
        }
    }
    
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    bfs(0,0);
    printf("%d", sumRoute[n-1][n-1]);
    
    return 0;
}

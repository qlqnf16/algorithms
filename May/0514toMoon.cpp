#include <cstdio>
#include <queue>
#define MAX 52
using namespace std;

typedef struct {
    int r, c, k, d;
} POS;
int H, W;
char board[MAX][MAX];
bool visit[MAX][MAX][1<<7];
bool keys[6];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
POS start;

int bfs() {
    int r, c, k, d, nr, nc, nk;
    char cell;
    queue<POS> posQueue;
    posQueue.push(start);
    visit[start.r][start.c][0] = true;
    
    while (!posQueue.empty()) {
        r = posQueue.front().r;
        c = posQueue.front().c;
        k = posQueue.front().k;
        d = posQueue.front().d;
        posQueue.pop();
        if (board[r][c] == '1') return d;
        
        for (int i = 0; i < 4; i++) {
            nr = r + dir[0][i];
            nc = c + dir[1][i];
            nk = k;
            cell = board[nr][nc];
            if (!cell || cell == '#') continue;
            if (cell >= 'A' && cell <= 'F') {
                if ((k & (1 << (cell - 'A'))) == 0) continue;
            }
            if (cell >= 'a' && cell <= 'f') nk = k | (1 << (cell - 'a'));

            if (visit[nr][nc][nk]) continue;
            visit[nr][nc][nk] = true;
            posQueue.push({nr, nc, nk, d+1});
        }
    }
    
    return -1;
}

int solve() {
    int res;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (board[i][j] == '0') {
                start.r = i;
                start.c = j;
                start.d = start.k = 0;
                break;
            }
        }
    }
    res = bfs();
    
    return res;
}

int main() {
    int ans;
    scanf("%d %d", &H, &W);
    for (int i = 1; i <= H; i++) {
        scanf("%s", &board[i][1]);
    }
    ans = solve();
    printf("%d", ans);
    return 0;
}

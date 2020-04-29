#include <stdio.h>
#include <queue>
#define MAX 50
using namespace std;

int N, M;
int house[MAX+2][MAX+2][4];
int visit[MAX+2][MAX+2];
int dir[][4] = {{0, -1, 0, 1}, {-1, 0, 1, 0}};  //서북동남
int roomCnt = 1;
int rooms[MAX*MAX+2];
bool roomRel[MAX*MAX+2][MAX*MAX+2];
struct POS {
    int c, r;
};

void checkWalls(int c, int r, int n) {
    for (int i = 0; i < 4; i++) {
        house[c][r][i] = n % 2;
        n /= 2;
    }
}

int bfs(int c, int r, int cnt) {
    int nc, nr, width = 0;
    queue<POS> posQueue;
    posQueue.push({c, r});
    visit[c][r] = cnt;
    
    while (!posQueue.empty()) {
        POS cur = posQueue.front();
        posQueue.pop();
        width ++;
        
        for (int i = 0; i < 4; i++) {
            if (house[cur.c][cur.r][i]) continue;
            nc = cur.c + dir[0][i];
            nr = cur.r + dir[1][i];
            if (nc < 0 || nc >= N || nr < 0 || nr >= M) continue;
            if (visit[nc][nr]) continue;
            visit[nc][nr] = cnt;
            posQueue.push({nc, nr});
        }
    }
    
    return width;
}

void calcRoomsAndWidth() {
    int max = 0, temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visit[i][j]) continue;
            temp = bfs(i, j, roomCnt);
            rooms[roomCnt++] = temp;
            if (temp > max) max = temp;
        }
    }
    
    printf("%d\n%d\n", roomCnt-1, max);
}

void findRoomRelations() {
    int nc, nr, roomI, roomJ;
    for (int c = 0; c < N; c++) {
        for (int r = 0; r < M; r++) {
            for (int d = 0; d < 4; d++) {
                if (!house[c][r][d]) continue;
                nc = c + dir[0][d];
                nr = r + dir[1][d];
                
                if (nc < 0 || nc >= N || nr < 0 || nr >= M) continue;
                if (visit[nc][nr] == visit[c][r]) continue;
                roomI = visit[c][r];
                roomJ = visit[nc][nr];
                roomRel[roomI][roomJ] = roomRel[roomJ][roomI] = true;
            }
        }
    }
}

void findNewMaxRoom() {
    int max = 0, temp;
    for (int i = 1; i <= roomCnt; i++) {
        for (int j = 1; j < i; j++) {
            if (!roomRel[i][j]) continue;
            temp = rooms[i] + rooms[j];
            if (temp > max) max = temp;
        }
    }
    printf("%d\n", max);
}


void solve() {
    calcRoomsAndWidth();
    findRoomRelations();
    findNewMaxRoom();
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int n;
            scanf("%d", &n);
            checkWalls(i, j, n);
        }
    }
    solve();
}

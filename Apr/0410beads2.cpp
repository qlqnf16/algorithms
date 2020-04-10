#include <cstdio>
#include <queue>
#define MAX 11
using namespace std;

typedef struct st {
    int redCol;
    int redRow;
    int blueCol;
    int blueRow;
} beads;
int C, R;
char map[MAX][MAX];
bool visit[MAX][MAX][MAX][MAX];
int route[MAX][MAX][MAX][MAX];
int dir[2][4] = {{0, 0, 1, -1,}, {1, -1, 0, 0}};
int nrc, nrr, nbc, nbr, gc, gr;
int success = 0;

bool isRedFirst(int d, beads bead) {
    if (d == 0 && bead.redCol == bead.blueCol && bead.redRow < bead.blueRow) return false;
    if (d == 1 && bead.redCol == bead.blueCol && bead.redRow > bead.blueRow) return false;
    if (d == 2 && bead.redRow == bead.blueRow && bead.redCol < bead.blueCol) return false;
    if (d == 3 && bead.redRow == bead.blueRow && bead.redCol > bead.blueCol) return false;
    return true;
}

void rollBeads(int d, beads bead, bool rollR) {
    int nc, nr;
    while (true) {
        if (rollR) {
            nc = nrc + dir[0][d];
            nr = nrr + dir[1][d];
        } else {
            nc = nbc + dir[0][d];
            nr = nbr + dir[1][d];
        }
//        printf("%d %d => ", nc, nr);
        if (nc < 0 || nc >= C || nr < 0 || nr >= R || map[nc][nr] == '#') break;
        if (map[nc][nr] == 'O') {
            if (rollR) {
                nrc = nc;
                nrr = nr;
            } else {
                nbc = nc;
                nbr = nr;
            }
            break;
        }
        if (rollR && nc == bead.blueCol && nr == bead.blueRow) break;
        if (!rollR && nc == bead.redCol && nr == bead.redRow) break;
        
        if (rollR) {
            nrc = nc;
            nrr = nr;
        } else {
            nbc = nc;
            nbr = nr;
        }
    }
//    printf("%d 방향으로 이동 => %d %d %d %d\n", d, nrc, nrr, nbc, nbr);
}

void bfs(int rc, int rr, int bc, int br) {
    beads current;
    queue<beads> beadsQueue;
    beadsQueue.push({rc, rr, bc, br});
    visit[rc][rr][bc][br] = true;
    
    while (!beadsQueue.empty()) {
        current = beadsQueue.front();
        beadsQueue.pop();
        //printf("=> %d %d %d %d\n", current.redCol, current.redRow, current.blueCol, current.blueRow);
        
        for (int i = 0; i < 4; i++) {
            nrc = current.redCol;
            nrr = current.redRow;
            nbc = current.blueCol;
            nbr = current.blueRow;
            if (isRedFirst(i, current)) {
                rollBeads(i, current, true);
                rollBeads(i, {nrc, nrr, current.blueCol, current.blueRow}, false);
            } else {
                rollBeads(i, current, false);
                rollBeads(i, {current.redCol, current.redRow, nbc, nbr}, true);
            }
            
            if (nbc == gc && nbr == gr) continue;
            if (!visit[nrc][nrr][nbc][nbr]) {
                //printf("%d %d %d %d\n", nrc, nrr, nbc, nbr);
                visit[nrc][nrr][nbc][nbr] = true;
                route[nrc][nrr][nbc][nbr] = route[current.redCol][current.redRow][current.blueCol][current.blueRow] + 1;
                beadsQueue.push({nrc, nrr, nbc, nbr});
            }
            if (nrc == gc && nrr == gr) {
                success = route[nrc][nrr][nbc][nbr];
                return;
            }
            if (route[nrc][nrr][nbc][nbr] >= 10) return;
        }
    }
}

int main(void) {
    int rc, rr, bc, br;
    scanf("%d %d", &C, &R);
    for (int i = 0; i < C; i++) {
        scanf("%s", map[i]);
    }
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            if (map[i][j] == 'B') {
                bc = i;
                br = j;
            }
            if (map[i][j] == 'R') {
                rc = i;
                rr = j;
            }
            if (map[i][j] == 'O') {
                gc = i;
                gr = j;
            }
        }
    }
    
    bfs(rc, rr, bc, br);
    if (success) printf("%d", success);
    else printf("-1");
    
    return 0;
}

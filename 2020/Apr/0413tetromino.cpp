#include <cstdio>
using namespace std;
#define MAX 510

int C, R, max;
int board[MAX][MAX];

int tertoc[][4] = {{0,0,0,0}, {0,1,2,3}, {0,0,1,1}, {0,0,0,1}, {0,0,1,2}, {1,1,1,0}, {0,1,2,2}, {0,0,0,1}, {0,1,2,2}, {0,1,1,1}, {0,0,1,2}, {0,1,1,2}, {1,1,0,0}, {0,1,1,2}, {0,0,1,1}, {0,1,1,1}, {0,1,1,2}, {0,1,1,2}, {0,0,0,1}};
int tertor[][4] = {{0,1,2,3}, {0,0,0,0}, {0,1,0,1}, {0,1,2,0}, {0,1,1,1}, {0,1,2,2}, {0,0,0,1}, {0,1,2,2}, {1,1,1,0}, {0,0,1,2}, {0,1,0,0}, {0,0,1,1}, {0,1,1,2}, {1,0,1,0}, {0,1,1,2}, {1,0,1,2}, {0,0,1,0}, {1,0,1,1}, {0,1,2,1}};

void solve() {
    int temp, ni, nj, k;
    for (int t = 0; t < 19; t++) {
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                temp = 0;
                for (k = 0; k < 4; k++) {
                    ni = i + tertoc[t][k];
                    nj = j + tertor[t][k];
                    if (ni < 0 || ni > C || nj < 0 || nj > R) break;
                    temp += board[ni][nj];
                }
                if (k == 4 && temp > max) max = temp;
            }
        }
    }
}

int main() {
    scanf("%d %d", &C, &R);
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    solve();
    printf("%d", max);
    
    return 0;
}


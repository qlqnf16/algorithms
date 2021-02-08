#include <cstdio>
#include <algorithm>
#define MAX 27
using namespace std;

int N;
char map[MAX][MAX];
int house;
int sol[MAX*MAX];
int dir[][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

void inputData() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%s", &map[i][1]);
    }
}

void outputData(int ans) {
    printf("%d\n", ans);
    sort(sol, sol+ans);
    for (int i = 0; i < ans; i++) {
        printf("%d\n", sol[i]);
    }
}

void floodFill(int c, int r) {
    if (map[c][r] != '1') return;
    map[c][r] = '0'; // 중복방문 표시
    house ++;
    for (int i = 0; i < 4; i++) {
        floodFill(c + dir[0][i], r + dir[1][i]);
    }
}

int solve() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == '1') {
                house = 0;
                floodFill(i, j);
                sol[cnt++] = house;
            }
        }
    }
    return cnt;
}

int main() {
    inputData();
    int ans = solve();
    outputData(ans);
    return 0;
}


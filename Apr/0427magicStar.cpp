#include <stdio.h>

char star[5][10];
bool visit[12];
int empty[12][2];
int emptyCnt;

int lines[][4][2] = {{{1,1}, {1,3}, {1,5}, {1,7}}, {{3, 1}, {3, 3}, {3, 5}, {3,7}}, {{0,4}, {1, 3}, {2, 2}, {3, 1}}, {{0, 4}, {1,5}, {2,6}, {3,7}}, {{1,1}, {2,2}, {3,3}, {4,4}}, {{4,4}, {3,5}, {2,6}, {1,7}}};

bool isPossible() {
    int c, r, tempsum;
    for (int i = 0; i < 6; i++) {
        tempsum = 0;
        for (int j = 0; j < 4; j++) {
            c = lines[i][j][0];
            r = lines[i][j][1];
            tempsum += star[c][r] - 'A' + 1;
        }
        if (tempsum != 26) return false;
    }
    return true;
}

int dfs(int n) {
    if (n >= emptyCnt) {
        if (isPossible()) return 1;
        return 0;
    }
    int c = empty[n][0];
    int r = empty[n][1];
    
    for (int i = 0; i < 12; i++) {
        if (visit[i]) continue;
        visit[i] = true;
        star[c][r] = i + 'A';
        if (dfs(n+1)) return 1;
        star[c][r] = 'x';
        visit[i] = false;
        
    }
    return 0;
}

void solve() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (star[i][j] == '.') continue;
            if (star[i][j] == 'x') {
                empty[emptyCnt][0] = i;
                empty[emptyCnt][1] = j;
                emptyCnt++;
            } else {
                visit[star[i][j] - 'A'] = true;
            }
        }
    }
    dfs(0);
}

int main() {
    for (int i = 0; i < 5; i++) {
        scanf("%s", star[i]);
    }
    solve();
    for (int i = 0; i < 5; i++) {
        printf("%s\n", star[i]);
    }
    return 0;
}

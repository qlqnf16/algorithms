#include <stdio.h>

struct POS {
    int c, r, energy;
};
int missiles, power, range;
int N, ans = 30;
POS warships[16];
int shootLocs[16], damages[16];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &warships[i].r, &warships[i].c, &warships[i].energy);
    }
    scanf("%d %d %d", &missiles, &power, &range);
}

int abs(int num) {
    return num < 0 ? -num : num;
}

int calcLeftShips() {
    int leftShips = N;
    for (int i = 0; i < N; i++) {
        if (warships[i].energy <= 0) leftShips --;
    }
    
    return leftShips;
}

void dfs(int n, int s) {
    if (n >= missiles) {
        int left = calcLeftShips();
        if (left < ans) ans = left;
        return;
    }
    
    for (int i = s; i < N; i++) {
        if (warships[i].energy <= 0) continue;
        for (int w = 0; w < N; w++) {
            if (abs(warships[i].c - warships[w].c) + abs(warships[i].r - warships[w].r) <= range) {
                warships[w].energy -= power;
            }
        }
        dfs(n+1, i);
        for (int w = 0; w < N; w++) {
            if (abs(warships[i].c - warships[w].c) + abs(warships[i].r - warships[w].r) <= range) {
                warships[w].energy += power;
            }
        }
    }
}

int main() {
    input();
    dfs(0, 0);
    printf("%d", ans);
    
    return 0;
}

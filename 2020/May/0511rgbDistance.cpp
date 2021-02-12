#include <stdio.h>
#define MAX 1001

int N;
int houses[MAX][3];
int dp[MAX][3];

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

void solve() {
    int res;
    for (int i = 0; i < 3; i++) {
        dp[1][i] = houses[1][i];
    }
    
    for (int i = 2; i <= N; i++) {
        dp[i][0] = min(houses[i][0] + dp[i-1][1], houses[i][0] + dp[i-1][2]);
        dp[i][1] = min(houses[i][1] + dp[i-1][0], houses[i][1] + dp[i-1][2]);
        dp[i][2] = min(houses[i][2] + dp[i-1][0], houses[i][2] + dp[i-1][1]);
    }
    
    res = min(min(dp[N][0], dp[N][1]), dp[N][2]);
    printf("%d", res);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &houses[i][j]);
        }
    }
    solve();
    
    return 0;
}

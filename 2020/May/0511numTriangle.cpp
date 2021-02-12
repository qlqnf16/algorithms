#include <stdio.h>
#define MAX 505

int N;
int nums[MAX][MAX];
int dp[MAX][MAX];

int max(int a, int b) {
    if (a < b) return b;
    return a;
}

void solve() {
    int res = 0;
    dp[0][0] = nums[0][0];
    dp[1][0] = dp[0][0] + nums[1][0];
    dp[1][1] = dp[0][0] + nums[1][1];
    
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) dp[i][j] = dp[i-1][0] + nums[i][0];
            else if (j == i) dp[i][j] = dp[i-1][i-1] + nums[i][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + nums[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (dp[N-1][i] > res) res = dp[N-1][i];
    }
    
    printf("%d", res);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &nums[i][j]);
        }
    }
    
    solve();

    return 0;
}

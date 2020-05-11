#include <stdio.h>
#define MAX 303

int N;
int scores[MAX];
int dp[MAX][2];

int max(int a, int b) {
    if (a < b) return b;
    return a;
}

void solve() {
    int res;
    dp[1][0] = dp[1][1] = scores[1];
    dp[2][0] = scores[2];
    dp[2][1] = scores[1] + scores[2];
    dp[3][0] = scores[1] + scores[3];
    dp[3][1] = scores[2] + scores[3];
    
    for (int i = 3; i <= N; i++) {
        dp[i][0] = scores[i] + max(dp[i-2][0], dp[i-2][1]);
        dp[i][1] = scores[i] + dp[i-1][0];
    }
    
    res = max(dp[N][0], dp[N][1]);
    printf("%d", res);
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &scores[i]);
    }
    solve();
    
    return 0;
}

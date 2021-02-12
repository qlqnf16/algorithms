#include <stdio.h>
#define MAX 10010

int N;
int cups[MAX];
int dp[MAX];

int max(int a, int b) {
    return a < b ? b : a;
}

void solve() {
    dp[0] = cups[0];
    dp[1] = cups[0] + cups[1];
    for (int i = 2; i < N; i++) {
        dp[i] = max(cups[i] + dp[i-2], cups[i] + cups[i-1] + dp[i-3]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    printf("%d", dp[N-1]);
}

int main() {
    scanf("%d", &N);
    for (int i =0; i < N; i++) {
        scanf("%d", &cups[i]);
    }
    solve();
    return 0;
}

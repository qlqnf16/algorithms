#include <stdio.h>

int N, M, K;

int min(int a, int b) {
    return a < b ? a : b;
}

int solve() {
    int teams, rest;
    teams = min(N/2, M);
    rest = N + M - (teams * 3);
    if (rest >= K) return teams;
    return teams - ((K - rest - 1) / 3 + 1);
}

int main() {
    int ans;
    scanf("%d %d %d", &N, &M, &K);
    ans = solve();
    printf("%d", ans);
    
    return 0;
}

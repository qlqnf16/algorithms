#include <stdio.h>
#define MAXM 55
#define INF 1010

int N, M;
int minPack, minUnit;
int packPrices[MAXM];
int unitPrices[MAXM];

int solve() {
    int share, rest;
    minPack = minUnit = INF;
    for (int i = 0; i < M; i++) {
        if (packPrices[i] < minPack) minPack = packPrices[i];
        if (unitPrices[i] < minUnit) {
            minUnit = unitPrices[i];
            if (minUnit * 6 < minPack) minPack = minUnit * 6;
        }
    }
    
    share = N / 6;
    rest = N % 6;
    if (rest * minUnit < minPack) return share * minPack + rest * minUnit;
    return (share + 1) * minPack;
}

int main() {
    int ans;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &packPrices[i], &unitPrices[i]);
    }
    ans = solve();
    printf("%d", ans);
    
    return 0;
}

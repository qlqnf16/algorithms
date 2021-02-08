#include <stdio.h>
#define MAX 50010

int N, Q;
int nums[MAX];
int sums[MAX];

void fillSums() {
    for (int i = 1; i <= N; i++) {
        sums[i] = sums[i-1] + nums[i];
    }
}

void solve() {
    int fromI, toI, ans;
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &fromI, &toI);
        ans = sums[toI] - sums[fromI-1];
        printf("%d\n", ans);
    }
}

int main() {
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &nums[i]);
    }
    fillSums();
    solve();
    return 0;
}

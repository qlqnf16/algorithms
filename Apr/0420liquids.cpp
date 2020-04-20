#include <stdio.h>
#define MAX 100010

int N;
int liquids[MAX];

int abs(int n) {
    if (n < 0) return -n;
    return n;
}

void solve() {
    int sum, s = 0, e = N-1, min = 2100000000, fromi, toi;
    while (s < e) {
        sum = liquids[s] + liquids[e];
        if (min >  abs(sum)) {
            min = abs(sum);
            fromi = s;
            toi = e;
        }
        if (sum < 0) s++;
        else if (sum > 0) e--;
        else break;
    }
    printf("%d %d", liquids[fromi], liquids[toi]);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &liquids[i]);
    }
    solve();
    return 0;
}

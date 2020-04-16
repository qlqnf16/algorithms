#include <cstdio>
using namespace std;
#define MAX 11

int N, K;
int coins[MAX];
int total;

void solve() {
    int left = K;
    for (int i = N-1; i >= 0; i--) {
        if (coins[i] <= left) {
            total += (left / coins[i]);
            left -= (left / coins[i]) * coins[i];
        }
        if (!left) break;
    }
    printf("%d", total);
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &coins[i]);
    }
    solve();
    
    return 0;
}

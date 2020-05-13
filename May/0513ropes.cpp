#include <cstdio>
#include <algorithm>
#define MAX 100010
using namespace std;

int N;
int ropes[MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

int solve() {
    int maxWeight = 0;
    sort(ropes, ropes+N);
    for (int i = 0; i < N; i++) {
        if (ropes[i] * (N-i) > maxWeight) maxWeight = ropes[i] * (N-i);
    }
    return maxWeight;
}

int main() {
    int ans;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &ropes[i]);
    }
    ans = solve();
    printf("%d", ans);
    
    return 0;
}

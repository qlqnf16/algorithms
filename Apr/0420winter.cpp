// 월동준비

#include <cstdio>
#define MAX 100010
using namespace std;

int N;
int acorns[MAX];
int dp[MAX];

int findStupidAnswer() {
    dp[0] = acorns[0];
    int max = dp[0];
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i-1] < 0 ? acorns[i] : dp[i-1] + acorns[i];
        if (dp[i] > max) max = dp[i];
    }
    return max;
}

int main() {
    int cans = 0, sans;
    int minusMax = -98798;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &acorns[i]);
        if (acorns[i] > 0) cans += acorns[i];
        if (acorns[i] < 0 && minusMax < acorns[i]) minusMax = acorns[i];
    }
    
    if (!cans) cans = minusMax;
    sans = findStupidAnswer();
    printf("%d %d", sans, cans);
    return 0;
}

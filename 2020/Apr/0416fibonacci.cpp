#include <cstdio>
using namespace std;
#define MAX 45

int dp[MAX][2];
int lastvisit = 3;
bool visit[MAX];

void solve(int num) {
    if (!visit[num]) {
        for (int i = lastvisit; i <= num; i++) {
            dp[i][0] = dp[i-1][0] + dp[i-2][0];
            dp[i][1] = dp[i-1][1] + dp[i-2][1];
            visit[i] = true;
        }
        if (num + 1 > lastvisit) lastvisit = num + 1;
    }
    printf("%d %d\n", dp[num][0], dp[num][1]);
}

int main() {
    int T, num;
    visit[0] = visit[1] = visit[2] = true;
    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &num);
        solve(num);
    }
    
    return 0;
}

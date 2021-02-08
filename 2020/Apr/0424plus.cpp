#include <stdio.h>
#define MAX 20

int N, K;
int numbers[MAX];
bool success;

void dfs(int idx, int sum) {
    if (idx > N || sum > K) return;
    if (sum == K) {
        success = true;
        return;
    }
    
    dfs(idx+1, sum + numbers[idx]);
    if (success) return;
    dfs(idx+1, sum);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        success = false;
        scanf("%d %d", &N, &K);
        for (int i = 0; i < N; i++) {
            scanf("%d", &numbers[i]);
        }
        dfs(0, 0);
        if (success) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

#include <stdio.h>
#define MAX 12

int N, M;
int graph[MAX][MAX];
int colored[MAX];

bool canColor(int n, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[n][i] && colored[i] == c) return false;
    }
    return true;
}

int dfs(int n) {
    if (n > N) return 1;
    for (int i = 1; i <= M; i++) {
        if (!canColor(n, i)) continue;
        colored[n] = i;
        if (dfs(n+1)) return 1;
    }
    return 0;
}

int main() {
    int done = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            int a;
            scanf("%d", &a);
            graph[i][j] = a;
            graph[j][i] = a;
        }
    }
    
    done = dfs(0);

    if (!done) {
        printf("-1");
    } else {
        for (int i = 0; i < N; i++) {
            printf("%d ", colored[i]);
        }
    }
    
    return 0;
}

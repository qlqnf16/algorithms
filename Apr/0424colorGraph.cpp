#include <stdio.h>
#define MAX 12

int N, M;
int graph[MAX][MAX];
int colored[MAX];
bool done;

bool canColor(int n, int c) {
    for (int i = 0; i < N; i++) {
        if (graph[n][i] && colored[i] == c) return false;
    }
    return true;
}

void dfs(int n) {
    if (n > N) {
        done = true;
        return;
    }
    for (int i = 1; i <= M; i++) {
        if (canColor(n, i)) {
            colored[n] = i;
            dfs(n+1);
            if (done) return;
            colored[n] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            int a;
            scanf("%d", &a);
            graph[i][j] = a;
            graph[j][i] = a;
        }
    }
    
    dfs(0);

    if (!done) {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", colored[i]);
    }
    
    return 0;
}

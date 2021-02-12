
#include <cstdio>
#define MAX 10010
using namespace std;

int N;
int graph[MAX][2];
int width[MAX][2];
bool isChild[MAX];

int row = 1;

void dfs(int v, int depth) {
    int left = graph[v][0];
    int right = graph[v][1];
    
    if (left) dfs(left, depth+1);
    if (!width[depth][0] || width[depth][0] > row) width[depth][0] = row;
    if (width[depth][1] < row) width[depth][1] = row;
    row++;
    if (right) dfs(right, depth+1);
    
}

int findRoot(void) {
    for (int i = 1; i <= N; i++) {
        if (graph[i][0]) isChild[graph[i][0]] = true;
        if (graph[i][1]) isChild[graph[i][1]] = true;
    }
    
    for (int i = 1; i <= N; i++) {
        if (!isChild[i]) return i;
    }
    
    return -1;
}

void solve(void) {
    int temp, maxWidth = 0, maxNum = 1;
    
    dfs(findRoot(), 1);
    for (int i = 1; i <= N; i++) {
        temp = width[i][1] - width[i][0] + 1;
        if (temp > maxWidth) {
            maxWidth = temp;
            maxNum = i;
        }
    }
    
    printf("%d %d", maxNum, maxWidth);
}

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int par, left, right;
        scanf("%d %d %d", &par, &left, &right);
        if (left != -1) graph[par][0] = left;
        if (right != -1) graph[par][1] = right;
    }
    solve();
    
    return 0;
}

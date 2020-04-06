#include <cstdio>
#include <vector>
#define MAX 110

using namespace std;

int N, M, middle;
vector<int> heavier[MAX];
vector<int> lighter[MAX];
bool visited[MAX];
int cnt;

void dfs(int v) {
    int next;
    visited[v] = true;
    if (cnt >= middle) return;
    for (int i = 0; i < heavier[v].size(); i++) {
        next = heavier[v][i];
        if (!visited[next]) {
            cnt++;
            dfs(next);
        }
    }
}

void dfs2(int v) {
    int next;
    visited[v] = true;
    if (cnt >= middle) return;
    for (int i = 0; i < lighter[v].size(); i++) {
        next = lighter[v][i];
        if (!visited[next]) {
            cnt++;
            dfs2(next);
        }
    }
}

void initVisitArray(void) {
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }
}

int main(void) {
    int sol = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        heavier[b].push_back(a);
        lighter[a].push_back(b);
    }
    middle = (N+1)/2;
    
    for (int i = 1; i <= N; i++) {
        cnt = 0;
        initVisitArray();
        dfs(i);
        if (cnt >= middle) {
            sol++;
            continue;
        }
        
        cnt = 0;
        initVisitArray();
        dfs2(i);
        if (cnt >= middle) sol++;
    }
    
    printf("%d", sol);
    return 0;
}

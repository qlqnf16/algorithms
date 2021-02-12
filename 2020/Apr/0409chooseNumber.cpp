#include <cstdio>
#include <vector>
#define MAX 101
using namespace std;

int N, cnt;
int graph[MAX];
vector<int> answer;
bool visit[MAX];

void initiate(void) {
    for (int i = 1; i <= N; i++) {
        visit[i] = 0;
    }
}

void dfs(int v, int start) {
    if (visit[v]) {
        if (v == start) answer.push_back(start);
    } else {
        visit[v] = true;
        dfs(graph[v], start);
    }
}

int main(void) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &graph[i]);
    }
    for (int i = 1; i <= N; i++) {
        dfs(i, i);
        initiate();
    }
    printf("%d\n", (int)answer.size());
    for (int i = 0; i < answer.size(); i++) {
        printf("%d\n", answer[i]);
    }
    
    return 0;
}

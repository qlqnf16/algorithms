#include <cstdio>
#include <vector>
#define MAX 1010
using namespace std;

int N, M;
vector<int> graph[MAX];
bool visit[MAX];

void input();
int solve();

int main() {
  input();
  int ans = solve();
  printf("%d", ans);
  return 0;
}

void input() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}

void dfs(int node) {
  if (visit[node])
    return;
  visit[node] = true;
  for (int i = 0; i < graph[node].size(); i++) {
    dfs(graph[node][i]);
  }
}

int solve() {
  int res = 0;
  for (int i = 1; i <= N; i++) {
    if (visit[i])
      continue;
    res++;
    dfs(i);
  }
  return res;
}
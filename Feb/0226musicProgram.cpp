#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define MAX 1000 + 5
using namespace std;

int N, M;
int indegree[MAX];
int result[MAX];
vector<int> graph[MAX];
queue<int> q;

void input();
void init();
bool topoSort();

void solve() {
  init();
  bool possible = topoSort();
  if (!possible) {
    printf("0");
  } else {
    for (int i = 0; i < N; i++) {
      printf("%d\n", result[i]);
    }
  }
}

void init() {
  for (int i = 1; i <= N; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
}

bool topoSort() {
  int ri = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    result[ri++] = cur;

    for (int i = 0; i < graph[cur].size(); i++) {
      int next = graph[cur][i];
      indegree[next]--;
      if (indegree[next] == 0)
        q.push(next);
    }
  }

  return ri == N;
}

int main() {
  input();
  solve();
  return 0;
}

void input() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    int num;
    scanf("%d", &num);
    int input, prev;
    for (int j = 0; j < num; j++) {
      scanf("%d", &input);
      if (j > 0) {
        graph[prev].push_back(input);
        indegree[input]++;
      }
      prev = input;
    }
  }
}
#include <cstdio>
#include <vector>
#define MAX 100000 + 10
using namespace std;

int N;
struct node {
  int val;
  int len;
};
vector<node> graph[MAX];
int tempMax;
int maxNode;
int ans;

void input();

void dfs(int current, int past, int length) {
  if (length > tempMax) {
    tempMax = length;
    maxNode = current;
  }

  for (int i = 0; i < graph[current].size(); i++) {
    node next = graph[current][i];
    if (next.val != past) {
      dfs(next.val, current, length + next.len);
    }
  }
}

void solve() {
  dfs(1, 0, 0);
  tempMax = 0;
  dfs(maxNode, 0, 0);
  ans = tempMax;
}

int main() {
  input();
  solve();
  printf("%d", ans);
  return 0;
}

void input() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int a, b, l;
    scanf("%d", &a);
    while (true) {
      scanf("%d", &b);
      if (b == -1)
        break;
      scanf("%d", &l);
      node newNode = {b, l};
      graph[a].push_back(newNode);
    }
  }
}

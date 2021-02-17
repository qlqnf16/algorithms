#include <cstdio>
#include <vector>
#define MAX 100010
using namespace std;

int N;
vector<int> graph[MAX];
bool visit[MAX];
int parent[MAX];

void input();
void init();

void dfs(int node) {
	visit[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (visit[next]) continue;
		parent[next] = node;
		dfs(next);
	}
}

void solve() {
	dfs(1);
	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}
}

int main() {
	input();
	solve();
	return 0;
}

void input() {
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

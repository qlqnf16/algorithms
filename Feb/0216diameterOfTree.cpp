#include <cstdio>
#include <vector>
#define MAX 10010
using namespace std;

int N;
struct node {
	int val;
	int cost;
};
vector<node> graph[MAX];

int maxNode;
int maxDist;

void input();

void dfs(int x, int past, int dist) {
	if (dist > maxDist) {
		maxNode = x;
		maxDist = dist;
	}

	for (int i = 0; i < graph[x].size(); i++) {
		node next = graph[x][i];
		if (next.val == past) continue;
		dfs(next.val, x, dist + next.cost);
	}
}

void solve() {
	dfs(1, 0, 0);
	maxDist = 0;
	dfs(maxNode, 0, 0);
	printf("%d", maxDist);
}

int main() {
	input();
	solve();

	return 0;
}

void input() {
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
}
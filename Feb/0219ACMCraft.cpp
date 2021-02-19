#include <cstdio>
#include <vector>
#include <queue>
#define MAX 1010
using namespace std;

int N, K, W;
int D[MAX];
int inbound[MAX];
int maxTime[MAX];
vector<int> graph[MAX];
queue<int> q;

void input();
void init();

int max(int a, int b) {
	return a > b ? a : b;
}

void bfs() {
	while (!q.empty()) {
		int num = q.front();
		q.pop();

		if (num == W) return;

		for (int i = 0; i < graph[num].size(); i++) {
			int next = graph[num][i];
			inbound[next]--;
			maxTime[next] = max(maxTime[next], maxTime[num] + D[next]);
			if (inbound[next] == 0) q.push(next);
		}
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		if (inbound[i]) continue;
		q.push(i);
		maxTime[i] = D[i];
	}
	bfs();
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		input();
		solve();
		printf("%d\n", maxTime[W]);
		init();
	}
	return 0;
}

void init() {
	q = queue<int>();
	for (int i = 0; i <= N; i++) {
		graph[i].clear();
		inbound[i] = 0;
		maxTime[i] = 0;
	}
}

void input() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &D[i]);
	}
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		inbound[b]++;
	}
	scanf("%d", &W);
}
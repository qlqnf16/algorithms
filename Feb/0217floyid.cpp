#include <cstdio>
#define MAX 110
#define INF 1000000000
using namespace std;

int n, m;
int graph[MAX][MAX];

void input();
void output();
void init();

int min(int a, int b) {
	return a > b ? b : a;
}

void solve() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

int main() {
	input();
	solve();
	output();
	return 0;
}

void input() {
	scanf("%d", &n);
	scanf("%d", &m);
	init();
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = min(graph[a][b], c);
	}
}

void output() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cost = graph[i][j];
			if (cost == INF) cost = 0;
			printf("%d ", cost);
		}
		printf("\n");
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j] = i == j ? 0 : INF;
		}
	}
}
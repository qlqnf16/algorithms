#include <cstdio>
#include <vector>
#define MAX 28
using namespace std;

int N;
int graph[MAX][2];

void input();

void dfs(char cur, int order) {
	if (cur == '.') return;
	int curIdx = cur - 'A';

	if (order == 0) printf("%c", cur);
	dfs(graph[curIdx][0], order);
	if (order == 1) printf("%c", cur);
	dfs(graph[curIdx][1], order);
	if (order == 2) printf("%c", cur);
}

void solve() {
	char root = 'A';
	dfs(root, 0);
	printf("\n");
	dfs(root, 1);
	printf("\n");
	dfs(root, 2);
}

int main() {
	input();
	solve();

	return 0;
}

void input() {
	scanf("%d\n", &N);
	char n, l, r;
	for (int i = 0; i < N; i++) {
		scanf("%c %c %c", &n, &l, &r);
		getchar();
		graph[n - 'A'][0] = l;
		graph[n - 'A'][1] = r;
	}
}
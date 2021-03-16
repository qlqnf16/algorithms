#include <cstdio>
#define MAX 100010
using namespace std;

int N;
int choices[MAX];
int visit[MAX];
bool isCycle[MAX];

int dfs(int cur, int flg) {
	int next = choices[cur];
	visit[cur] = flg;

	if (isCycle[next]) return 0;
	if (visit[next] == flg) {
		isCycle[cur] = true;
		return next;
	}
	if (visit[next] != 0) {
		return 0;
	}

	int ret = dfs(next, flg);
	if (ret) isCycle[cur] = true;
	if (ret == cur) ret = 0;
	return ret;
}

int solve() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (isCycle[i] || visit[i] > 0) continue;
		dfs(i, i);
	}
	for (int i = 1; i <= N; i++) {
		if (!isCycle[i]) ans++;
	}
	return ans;
}

void init() {
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
		isCycle[i] = false;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &choices[i]);
			if (choices[i] == i) isCycle[i] = true;
		}
		printf("%d\n", solve());
		init();
	}

	return 0;
}
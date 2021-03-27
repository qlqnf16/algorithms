#include <cstdio>
#include <queue>
#include <stack>
#define MAX 1000010
using namespace std;

int N;
int memo[MAX][2];
queue<int> q;

int fillMemo(int next, int cnt, int method) {
	if (next <= 0 || (memo[next][0] && memo[next][0] <= cnt)) return 0;
	memo[next][0] = cnt;
	memo[next][1] = method;
	if (next == 1) return 1;

	q.push(next);
	return 0;
}

void bfs() {
	q.push(N);

	while (!q.empty()) {
		int cur = q.front();
		int cnt = memo[cur][0] + 1;
		q.pop();

		// devide 3
		if (cur % 3 == 0) {
			int next = cur / 3;
			if (fillMemo(next, cnt, 1)) break;
		}
		// devide 2
		if (cur % 2 == 0) {
			int next = cur / 2;
			if (fillMemo(next, cnt, 2)) break;
		}
		// minus 1
		int next = cur - 1;
		if (fillMemo(next, cnt, 3)) break;
	}

	printf("%d\n", memo[1][0]);
}

void printTrace() {
	stack<int> trace;
	int cur = 1;
	while (true) {
		trace.push(cur);
		if (cur == N) break;
		if (memo[cur][1] == 1) {
			cur *= 3;
		}
		else if (memo[cur][1] == 2) {
			cur *= 2;
		}
		else {
			cur += 1;
		}
	}

	while (!trace.empty()) {
		printf("%d ", trace.top());
		trace.pop();
	}
}

int main() {
	scanf("%d", &N);
	bfs();
	printTrace();
	return 0;
}
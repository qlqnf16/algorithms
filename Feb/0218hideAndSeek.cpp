#include <cstdio>
#include <queue>
#define MAX 100000
using namespace std;

int N, K;
int minTime[MAX+5];

struct ele {
	int loca;
	int time;
};

queue<ele> q;

void push(int loca, int time) {
	if (loca < 0 || loca > MAX) return;
	if (minTime[loca] == -1 || time < minTime[loca]) {
		minTime[loca] = time;
		q.push({ loca, time });
	}
}

void init() {
	for (int i = 0; i < MAX+5; i++) {
		minTime[i] = -1;
	}
}

int bfs() {
	init();
	q.push({ N, 0 });
	minTime[N] = 0;

	while (!q.empty()) {
		int loca = q.front().loca;
		int time = q.front().time;
		q.pop();

		if (minTime[loca] < time) continue;
		if (loca == K) return time;

		push(loca * 2, time);
		push(loca + 1, time+1);
		push(loca - 1, time+1);
	}
	return -1;
}

int main() {
	scanf("%d %d", &N, &K);
	int ans = bfs();
	printf("%d", ans);
	return 0;
}

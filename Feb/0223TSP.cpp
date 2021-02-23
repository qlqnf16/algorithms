#include <cstdio>
#include <algorithm>
#define MAX 16
#define INF 100000000
using namespace std;

int N;
int graph[MAX][MAX];
int dp[MAX][1 << MAX];

int TSP(int cur, int visited) {
	if (visited == (1 << N) - 1) {
		if (graph[cur][0] == 0) return INF;
		return graph[cur][0];
	}
	int time = dp[cur][visited];
	if (time != -1) {
		printf("%d\n", cur);
		return time;
	}
	time = INF;

	for (int i = 0; i < N; i++) {
		if (visited & (1 << i) || graph[cur][i] == 0) continue;
		time = min(time, TSP(i, visited | 1 << i) + graph[cur][i]);
	}

	return dp[cur][visited] = time;
}


void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
}

int main() {
	input();
	memset(dp, -1, sizeof(dp));
	printf("%d", TSP(0,1));

	return 0;
}
 
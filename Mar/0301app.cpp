#include <cstdio>
#include <algorithm>
#define MAXN 102
#define MAXC 10002
using namespace std;

int N, M;
int memory[MAXN];
int cost[MAXN];
int dp[MAXN][MAXC];

int solve() {
	int minc = 99999;

	for (int i = 1; i <= N; i++) {
		for (int c = 0; c <= MAXC; c++) {
			if (c > minc) break;
			if (cost[i] > c) {
				dp[i][c] = dp[i - 1][c];
			}
			else {
				dp[i][c] = max(dp[i-1][c], memory[i] + dp[i-1][c - cost[i]]);
			}
			if (dp[i][c] >= M) minc = c;
		}
	}

	return minc;
}

void input() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &memory[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &cost[i]);
	}
}

int main() {
	input();
	printf("%d", solve());
	return 0;
}
 
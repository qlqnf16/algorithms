#include <cstdio>
#define MAX 100000+10
using namespace std;

int N, K;
int dp[MAX];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int w, v;
		scanf("%d %d", &w, &v);

		for (int k = K; k >= w; k--) {
			dp[k] = max(dp[k], dp[k - w] + v);
		}
	}
	printf("%d", dp[K]);
	return 0;
}

#include <cstdio>
#define MAXN 500010
#define MAXC 20000001
#define TENM 10000000
using namespace std;

int N, M;
int num[MAXN];
int val[MAXN];
int cnt[MAXC];

void solve() {
	for (int i = 0; i < N; i++) {
		if (num[i] == 0) cnt[TENM]++;
		else cnt[TENM + num[i]]++;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &val[i]);
	}
	solve();
	for (int i = 0; i < M; i++) {
		printf("%d ", cnt[TENM + val[i]]);
	}

	return 0;
}
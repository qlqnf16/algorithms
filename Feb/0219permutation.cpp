#include <cstdio>
#include <algorithm>
#define MAX 8
using namespace std;

int N, M;
int nums[MAX];
int list[MAX];
bool visit[MAX];

void output() {
	for (int i = 0; i < M; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

void backtrack(int cur, int li) {
	list[li] = nums[cur];
	if (li == M - 1) {
		output();
	}

	for (int i = 0; i < N; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		backtrack(i, li+1);
		visit[i] = false;
	}
}

void solve() {
	sort(nums, nums + N);
	for (int i = 0; i < N; i++) {
		visit[i] = true;
		backtrack(i, 0);
		visit[i] = false;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}
	solve();
	return 0;
}

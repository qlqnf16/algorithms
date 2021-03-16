#include <cstdio>
#define MAX 1000010
using namespace std;

int N;
int nums[MAX];
int index[MAX];
int LIS[MAX];
int lsize = 0;

int findLowerBound(int n) {
	int s = 0;
	int e = lsize;
	int m;
	while (s < e) {
		m = (s + e) / 2;
		if (LIS[m] >= n) e = m;
		else s = m + 1;
	}
	return s;
}

void solve() {
	LIS[0] = nums[0];
	index[0] = 0;

	for (int i = 1; i < N; i++) {
		if (LIS[lsize] < nums[i]) {
			LIS[++lsize] = nums[i];
			index[i] = lsize;
		}
		else {
			int lb = findLowerBound(nums[i]);
			LIS[lb] = nums[i];
			index[i] = lb;
		}
	}

	int target = lsize;
	for (int i = N - 1; i >= 0; i--) {
		if (index[i] == target) {
			LIS[target] = nums[i];
			target--;
		}
	}

	printf("%d\n", lsize + 1);
	for (int i = 0; i < lsize + 1; i++) {
		printf("%d ", LIS[i]);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}
	solve();

	return 0;
}
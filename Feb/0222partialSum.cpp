#include <cstdio>
#include <algorithm>
#define MAX 100010
using namespace std;

int N, S;
int nums[MAX];

int solve() {
	int tempSum = nums[0];
	int minNums = MAX;
	int si = 0;
	int ei = 0;
	bool flag = false;
	while (ei < N && si < N) {
		if (tempSum < S) {
			ei++;
			tempSum += nums[ei];
		}
		else {
			flag = true;
			minNums = min(minNums, ei - si + 1);
			if (minNums == 1) break;
			tempSum -= nums[si];
			si++;
		}
	}

	return flag ? minNums : 0;
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}
	int ans = solve();
	printf("%d", ans);

	return 0;
}

#include <cstdio>
#include <algorithm>
#define MAX 100010
using namespace std;

int N;
struct line {
	int left;
	int right;
};
line lines[MAX];
int L[MAX];
int P[MAX];
int R[MAX];

bool comp(line a, line b) {
	return a.left < b.left;
}

int getLIS() {
	int li = 0;
	int pi = 0;
	sort(lines, lines + N, comp);
	for (int i = 0; i < N; i++) {
		int num = lines[i].right;
		if (li == 0 || L[li-1] < num) {
			L[li++] = num;
			P[i] = li - 1;
		}
		else {
			auto idx = lower_bound(L, L + li, num);
			*idx = num;
			P[i] = distance(L, idx);
		}
	}

	return li;
}

int getNumsToDelete(int target) {
	int ri = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (P[i] == target) target--;
		else {
			R[ri++] = lines[i].left;
		}
	}
	return ri;
}

void solve() {
	int length = getLIS();
	int numsToDelete = getNumsToDelete(length - 1);
	sort(R, R + numsToDelete);
	printf("%d\n", numsToDelete);
	for (int i = 0; i < numsToDelete; i++) {
		printf("%d\n", R[i]);
	}
}

void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &lines[i].left, &lines[i].right);
	}
}

int main() {
	input();
	solve();
	return 0;
}
 
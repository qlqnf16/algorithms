#include <cstdio>
#define MAX 2010
using namespace std;

int N, M;
int nums[MAX];
int isPalindrome[MAX][MAX];

void checkPalindrome() {
	for (int i = 1; i <= N; i++) {
		isPalindrome[i][i] = 1;
		if (i == N) break;
		if (nums[i] == nums[i + 1]) isPalindrome[i][i + 1] = 1;
	}

	for (int j = 2; j <= N; j++) {
		for (int i = 1; i <= N - j; i++) {
			if (nums[i] != nums[j + i]) continue;
			isPalindrome[i][j + i] = isPalindrome[i + 1][j + i - 1];
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &nums[i]);
	}
	checkPalindrome();
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int S, E;
		scanf("%d %d", &S, &E);
		printf("%d\n", isPalindrome[S][E]);
	}

	return 0;
}
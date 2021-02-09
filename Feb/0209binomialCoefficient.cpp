#include <cstdio>

using namespace std;

int N, K;

int calc(int n, int r) {
	// nCr = n-1Cr-1 + n-1Cr
	if (n == r) return 1;
	if (r == 1 || n - r == 1) return n;
	return calc(n - 1, r - 1) + calc(n - 1, r);
}

int main() {
	scanf("%d %d", &N, &K);
	printf("%d", calc(N, K));

	return 0;
}
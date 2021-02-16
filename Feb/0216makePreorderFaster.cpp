#include <cstdio>
#include <vector>
#define MAX 100010
using namespace std;

int N;
int inIdx[MAX];
int poOrd[MAX];

void input();

void preorder(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) return;
	int root = poOrd[pe];
	printf("%d ", root);
	preorder(is, inIdx[root] - 1, ps, ps + inIdx[root] - is - 1);
	preorder(inIdx[root] + 1, ie, ps + inIdx[root] - is, pe - 1);
}

int main() {
	input();
	preorder(0, N - 1, 0, N - 1);

	return 0;
}

void input() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		inIdx[input] = i;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &poOrd[i]);
	}
}
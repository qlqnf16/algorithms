#include <cstdio>
#include <vector>
#define MAX 100010
using namespace std;

int N;
int inOrd[MAX];
int poOrd[MAX];
int tree[MAX][2];

void input();

int makeTree(int s, int e, int pr) {
	if (s > e) return 0;
	if (s == e) return inOrd[s];

	int r;
	for (r = s; r <= e; r++) {
		if (inOrd[r] == poOrd[pr]) break;
	}
	int root = inOrd[r];
	tree[root][0] = makeTree(s, r - 1, pr - (e - r + 1));
	tree[root][1] = makeTree(r + 1, e, pr -1);
	return root;
}

void preorder(int node) {
	if (node == 0) return;
	printf("%d ", node);
	preorder(tree[node][0]);
	preorder(tree[node][1]);
}

void solve() {
	int root = makeTree(0, N - 1, N - 1);
	preorder(root);
}

int main() {
	input();
	solve();

	return 0;
}

void input() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &inOrd[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &poOrd[i]);
	}
}
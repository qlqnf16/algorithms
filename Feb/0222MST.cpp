#include <cstdio>
#include <algorithm>
#define MAXV 10010
#define MAXE 100010
using namespace std;

int V, E;
struct EDGE {
	int n1;
	int n2;
	int cost;
};
EDGE edges[MAXE];
int parent[MAXV];
int child[MAXV];

int find(int a);
int makeUnion(int a, int b);
bool areUnion(int a, int b);
bool comp(EDGE a, EDGE b);

void init() {
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
		child[i] = 1;
	}
}

int solve() {
	int totalCost = 0;
	init();
	sort(edges, edges + E, comp);
	for (int i = 0; i < E; i++) {
		if (areUnion(edges[i].n1, edges[i].n2)) continue;
		int chosenNodes = makeUnion(edges[i].n1, edges[i].n2);
		totalCost += edges[i].cost;
		if (chosenNodes == V) break;
	}
	return totalCost;
}

int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &edges[i].n1, &edges[i].n2, &edges[i].cost);
	}
	int ans = solve();
	printf("%d", ans);

	return 0;
}

int makeUnion(int a, int b) {
	int aroot = find(a);
	int broot = find(b);
	parent[aroot] = broot;
	child[broot] += child[aroot];

	return child[broot];
}

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

bool areUnion(int a, int b) {
	return find(a) == find(b);
}

bool comp(EDGE a, EDGE b) {
	return a.cost < b.cost;
}
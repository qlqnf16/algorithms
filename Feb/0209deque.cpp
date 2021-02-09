#include <cstdio>
#include <string>
#define MAXN 10010

using namespace std;

int deque[MAXN];
int N, fi, bi;

void pushFront(int x) {
	deque[fi] = x;
	fi = (N + (fi - 1)) % N;
}

void pushBack(int x) {
	bi = (N + (bi + 1)) % N;
	deque[bi] = x;
}

int popFront() {
	if (fi == bi) return -1;
	fi = (N + (fi + 1)) % N;
	return deque[fi];
}

int popBack() {
	if (fi == bi) return -1;
	int res = deque[bi];
	bi = (N + bi - 1) % N;
	return res;
}

int size() {
	if (bi == fi) return 0;
	else if (bi > fi) return bi - fi;
	else return bi + N - fi;
}


int empty() {
	return bi - fi ? 0 : 1;
}

int front() {
	if (fi == bi) return -1;
	return deque[(N + (fi + 1)) % N];
}

int back() {
	if (fi == bi) return -1;
	return deque[bi];
}


int main() {
	int x;
	char str[12] = "";
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		if (!strcmp(str,"push_front")) {
			scanf("%d", &x);
			pushFront(x);
		}
		else if (!strcmp(str, "push_back")) {
			scanf("%d", &x);
			pushBack(x);
		}
		else if (!strcmp(str, "pop_front")) {
			printf("%d\n", popFront());
		}
		else if (!strcmp(str, "pop_back")) {
			printf("%d\n", popBack());
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", size());
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", empty());
		}
		else if (!strcmp(str, "front")) {
			printf("%d\n", front());
		}
		else if (!strcmp(str, "back")) {
			printf("%d\n", back());
		}
		else {
			printf("ERROR %s\n", str);
		}
	}

	return 0;
}
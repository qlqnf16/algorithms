#include <cstdio>
#define MAX 110
using namespace std;

char input[MAX];
char answer[MAX];
char stack[MAX];
int ansIdx = 0;
int stkIdx = 0;

int calcRank(char ch) {
	if (ch == '(' || ch == ')') return 0;
	if (ch == '+' || ch == '-') return 1;
	if (ch == '*' || ch == '/') return 2;
	else return -1;
}

void emptyStack(char next) {
	while (true) {
		if (stkIdx <= 0) break;
		char top = stack[stkIdx-1];
		//printf("%c %c\n", next, top);
		if (next == ')' && top == '(') {
			stkIdx--;
			break;
		}
		if (next != ')' && calcRank(next) > calcRank(top)) {
			break;
		}
		stkIdx--;
		answer[ansIdx++] = top;
	}
}

void solve() {
	int inpIdx = 0;
	bool top = false;
	while (input[inpIdx]) {
		char cur = input[inpIdx++];
		if (cur >= 'A' && cur <= 'Z') {
			answer[ansIdx++] = cur;
		}
		else if (cur == '(') {
			stack[stkIdx++] = cur;
			top = false;
		}
		else if (cur == ')') {
			emptyStack(')');
		}
		else {
			emptyStack(cur);
			stack[stkIdx++] = cur;
		}
	}
	emptyStack(0);
}

int main() {
	scanf("%s", input);
	solve();
	printf("%s", answer);

	return 0;
}
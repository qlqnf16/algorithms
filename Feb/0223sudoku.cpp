#include <cstdio>
using namespace std;

int N;
int board[9][9];
int R[81];
int C[81];

bool isPossible(int r, int c, int n) {
	for (int i = 0; i < 9; i++) {
		if (board[i][c] == n || board[r][i] == n) return false;
	}
	for (int i = 3 * (r / 3); i < 3 * (r / 3 + 1); i++) {
		for (int j = 3 * (c / 3); j <  3* (c / 3 + 1); j++) {
			if (board[i][j] == n) return false;
		}
	}
	return true;
}

int sudoku(int idx, int end) {
	int r = R[idx];
	int c = C[idx];

	if (idx == end) {
		return 1;
	}

	for (int i = 1; i <= 9; i++) {
		if (isPossible(r, c, i)) {
			board[r][c] = i;
			if (sudoku(idx+1, end)) return 1;
			board[r][c] = 0;
		}
	}

	return 0;
}

void solve() {
	int idx = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j]) continue;
			R[idx] = i;
			C[idx] = j;
			idx++;
		}
	}
	sudoku(0, idx);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d", board[i][j]);
		}
		printf("\n");
	}
}

void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
}

int main() {
	input();
	solve();
	return 0;
}
 
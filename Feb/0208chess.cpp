#include <cstdio>
#define MAX 51

using namespace std;

int N, M;
char board[MAX][MAX];

int checkBoard(int sr, int sc) {
	int blackChange = 0;
	int whiteChange = 0;

	for (int i = sr; i < sr + 8; i++) {
		for (int j = sc; j < sc + 8; j++) {
			// Black
			if (i % 2 == 0) {
				if (j % 2 == 0 && board[i][j] == 'W') blackChange++;
				if (j % 2 == 1 && board[i][j] == 'B') blackChange++;
			}
			else {
				if (j % 2 == 0 && board[i][j] == 'B') blackChange++;
				if (j % 2 == 1 && board[i][j] == 'W') blackChange++;
			}

			// White
			if (i % 2 == 0) {
				if (j % 2 == 0 && board[i][j] == 'B') whiteChange++;
				if (j % 2 == 1 && board[i][j] == 'W') whiteChange++;
			}
			else {
				if (j % 2 == 0 && board[i][j] == 'W') whiteChange++;
				if (j % 2 == 1 && board[i][j] == 'B') whiteChange++;
			}
		}
	}

	return blackChange > whiteChange ? whiteChange : blackChange;
}

int solve() {
	int min = 5000;

	for (int i = 0; i < N; i++) {
		if (i + 8 > N) continue;
		for (int j = 0; j < M; j++) {
			if (j + 8 > M) continue; 
			int res = checkBoard(i, j);
			if (res < min) min = res;
		}
	}

	return min;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", board[i]);
	}
	printf("%d", solve());

	return 0;
}
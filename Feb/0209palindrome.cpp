#include <cstdio>
#include <string>

using namespace std;

char num[6];

bool solve(int len) {
	for (int i = 0; i < len / 2; i++) {
		if (num[i] != num[len-1-i]) return false;
	}
	return true;
}

int main() {
	while (true)
	{
		int input;
		int len = 0;
		scanf("%s", num);
		if (num[0] == '0') break;
		for (int i = 0; i < 6; i++, len++) {
			if (num[i] == 0) break;
		}
		
		solve(len) ? printf("yes\n") : printf("no\n");
	}

	return 0;
}
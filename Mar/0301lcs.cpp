#include <iostream>
#include <string>
#define MAX 1010
using namespace std;

string str1, str2;
string dp[MAX][MAX];

string strmax(string a, string b) {
	if (a.size() >= b.size()) return a;
	else return b;
}

void solve() {
	int len1 = str1.size();
	int len2 = str2.size();

	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (str1.at(i) == str2.at(j)) {
				if (i == 0 || j == 0) dp[i][j] = str1.at(i);
				else {
					dp[i][j] = strmax(dp[i - 1][j - 1] + str1.at(i), dp[i-1][j]);
				}
			}
			else {
				if (i == 0 && j == 0) dp[i][j] = "";
				else if (i == 0) dp[i][j] = dp[i][j - 1];
				else if (j == 0) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = strmax(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[len1 - 1][len2 - 1].size() << "\n";
	cout << dp[len1 - 1][len2 - 1];
}

void input() {
	cin >> str1 >> str2;
}

int main() {
	input();
	solve();
	return 0;
}
 
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#define MAX 110
using namespace std;

int n, m;
string combi[MAX][MAX];

string sum(string x, string y) {
	while (x.length() < y.length()) x += '0';
	while (x.length() > y.length()) y += '0';
	int xl = x.length();
	int num, carry = 0;
	string result = "";
	
	for (int i = 0; i < xl; i++) {
		int tempSum = (x[i] - '0') + (y[i] - '0') + carry;
		num = tempSum % 10;
		carry = tempSum / 10;
		result += num + '0';
	}
	if (carry) result += carry + '0';

	return result;
}

void calcCombi() {
	combi[1][1] = combi[2][2] = "1";
	combi[2][1] = "2";
	for (int i = 3; i <= n; i++) {
		string tmp = to_string(i);
		reverse(tmp.begin(), tmp.end());
		combi[i][1] = tmp;
		for (int j = 2; j <= m; j++) {
			if (j > i) break;
			combi[i][j] = sum(combi[i - 1][j - 1], combi[i - 1][j]);
		}
	}
}

void solve() {
	calcCombi();

	string result = sum(combi[n-1][m], combi[n-1][m-1]);
	reverse(result.begin(), result.end());
	printf("%s", result.c_str());
}

int main() {
	scanf("%d %d", &n, &m);
	solve();
	return 0;
}

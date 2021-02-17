#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#define MAX 10010
using namespace std;
	
string x, y;
string result;

void sum() {
	int xl = x.length();
	int num, carry = 0;
	for (int i = 0; i < xl; i++) {
		int tempSum = (x[i] - '0') + (y[i] - '0') + carry;
		num = tempSum % 10;
		carry = tempSum / 10;
		result += num + '0';
	}
	if (carry) result += carry + '0';
}

void solve() {
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	while (x.length() < y.length()) x += '0';
	while (x.length() > y.length()) y += '0';
	sum();
	reverse(result.begin(), result.end());
}

int main() {
	cin >> x >> y;
	solve();
	printf("%s", result.c_str());
	return 0;
}

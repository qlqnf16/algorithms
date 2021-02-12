#include <cstdio>
#include <algorithm>
#define MAX 100000
using namespace std;

char nums[MAX+10];

bool desc(int a, int b) {
    return a > b;
}

void solve() {
    int i = 0, sum = 0;
    bool isZero = false;
    while (true) {
        if (!nums[i]) break;
        if (nums[i] == '0') isZero = true;
        sum += nums[i++] - '0';
    }
    if (sum % 3 || !isZero) {
        printf("-1");
        return;
    }
    sort(nums, nums+i, desc);
    printf("%s", nums);
    
}

int main() {
    scanf("%s", nums);
    solve();
    
    return 0;
}

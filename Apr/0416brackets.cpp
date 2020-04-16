#include <cstdio>
using namespace std;
#define MAX 30

int sizeNum, sizeSym;
int nums[MAX];
char symbols[MAX];

void solve() {
    bool minus = false;
    int sum = nums[0];
    for (int i = 0, j = 1; i < sizeSym; i++, j++) {
        if (symbols[i] == '-') minus = true;
        if (minus) sum += nums[j] * -1;
        else sum += nums[j];
    }
    printf("%d", sum);
}

int main() {
    int idx = 0; char s;
    while (true) {
        scanf("%d", &nums[idx]);
        scanf("%c", &s);
        if (s == '\n') break;
        symbols[idx++] = s;
    }
    sizeNum = idx+1;
    sizeSym = idx;
    
    solve();
    return 0;
}

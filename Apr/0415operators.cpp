#include <cstdio>
#define MAX 15
using namespace std;

int N;
int maxx = -1100000000, minn = 1100000000;
int nums[MAX];
int symbol[4];

void pick(int idx, int cnt, int sum) {
    int nextsum = 0;
    if (cnt == N) {
        if (sum > maxx) maxx = sum;
        if (sum < minn) minn = sum;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (i == 0) nextsum = sum + nums[idx+1];
        if (i == 1) nextsum = sum - nums[idx+1];
        if (i == 2) nextsum = sum * nums[idx+1];
        if (i == 3) nextsum = sum / nums[idx+1];
        
        if (symbol[i]) {
            symbol[i] --;
            pick(idx+1, cnt+1, nextsum);
            symbol[i] ++;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &symbol[i]);
    }
    pick(0, 1, nums[0]);
    printf("%d\n%d", maxx, minn);
}

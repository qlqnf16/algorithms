#include <cstdio>
#include <algorithm>
#define MAX 100010
using namespace std;

int N;
long long liquids[MAX];

void solve() {
    int s = 0, e = N-1;
    long long sum, min = 3100000000;
    long long answer[3];
    for (int i = 0; i < N; i++) {
        s = 0; e = N-1;
        while (s < e) {
            sum = liquids[s] + liquids[e] + liquids[i];
            if (min >  abs(sum) && s!= i && e != i) {
                min = abs(sum);
                answer[0] = liquids[s];
                answer[1] = liquids[e];
                answer[2] = liquids[i];
            }
            if (sum < 0) s++;
            else if (sum > 0) e--;
            else break;
        }
    }
    sort(answer, answer+3);
    printf("%lld %lld %lld", answer[0], answer[1], answer[2]);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &liquids[i]);
    }
    sort(liquids, liquids+N);
    solve();
    return 0;
}

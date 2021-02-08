#include <cstdio>
#define MAX 3000010
using namespace std;

int N, d, k, c; // 접시수, 초밥의 가짓수, 연속 접시 수, 쿠폰 번호
int plates[MAX];
int chose[3001];

int solve() {
    int count = 0, max;
    
    for (int i = 0; i < k; i++) {
        if (!chose[plates[i]]) count++;
        chose[plates[i]] ++;
    }
    max = count;
    for (int i = 0; i < N; i++) {
        int sushi = plates[i];
        int nsushi = i + k >= N ? plates[i+k-N] : plates[i+k];
        
        chose[sushi]--;
        if(!chose[sushi]) count--;
        if (!chose[nsushi]) count++;
        chose[nsushi]++;
        
        if (count >= max) {
            max = chose[c] ? count : count + 1;
        }
    }
    return max;
}

int main() {
    int ans;
    scanf("%d %d %d %d", &N, &d, &k, &c);
    for (int i = 0; i < N; i++) {
        scanf("%d", &plates[i]);
    }
    ans = solve();
    printf("%d", ans);

    return 0;
}

#include <cstdio>
#define MAX 1010
using namespace std;

int N;
int vote[MAX][4];
int score[4];

int solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < 4; j++) {
            score[j] += (vote[i][j] << 10) + (vote[i][j] == 3);
        }
    }
    
    int maxidx = 1;
    for (int i = 2; i < 4; i++) {
        if (score[i] > score[maxidx]) maxidx = i;
        else if (score[i] == score[maxidx]) {
            maxidx = 0;
            score[0] = score[i];
        }
    }
    
    return maxidx;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < 4; j++) {
            scanf("%d", &vote[i][j]);
        }
    }
    
    int ans = solve();
    printf("%d %d", ans, score[ans] >> 10);

    return 0;
}

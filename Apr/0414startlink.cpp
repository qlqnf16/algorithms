#include <cstdio>
using namespace std;
#define MAX 21

int N, min = 987987987;
int team[MAX][MAX];
bool picked[MAX];

int abs(int n) {
    if (n < 0) return -n;
    return n;
}

void pickMember(int m, int n) {
    int startsum = 0, linksum = 0, diff;
    if (n == N/2) {
        for (int i = 0; i < N; i++) {
            if (picked[i]) {
                for (int j = 0; j < N; j++) {
                    if (j != i && picked[j]) startsum += team[i][j];
                }
            } else {
                for (int j = 0; j < N; j++) {
                    if (j != i && !picked[j]) linksum += team[i][j];
                }
            }
        }
        diff = abs(startsum-linksum);
        if (min > diff) min = diff;
        return;
    }
    
    for (int i = m+1; i < N; i++) {
        picked[i] = true;
        pickMember(i, n+1);
        picked[i] = false;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &team[i][j]);
        }
    }
    pickMember(-1, 0);
    printf("%d", min);
    
    return 0;
}

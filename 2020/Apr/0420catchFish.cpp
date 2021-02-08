#include <cstdio>
#define MAX 110
using namespace std;

int N, l, M;
int posc[MAX];
int posr[MAX];

int calcFishes(int sc, int sr, int ec, int er) {
    int count = 0;
    for (int i = 0; i < M; i++) {
        if (posc[i] >= sc && posc[i] <= ec && posr[i] >= sr && posr[i] <= er) count++;
    }
    return count;
}

int solve() {
    int w, h, max=0, temp;
    for (int i = 0; i < M; i++) {
        for (int j = 1; j < (l/2); j++) {
            w = j;
            h = (l/2) - j;
            for (int k = posc[i] - h; k <= posc[i]; k++) {
                for (int t = posr[i] - w; t <= posr[i]; t++) {
                    temp = calcFishes(k, t, k+h, t+w);
                    if (temp > max) max = temp;
                }
            }
        }
    }
    return max;
}

int main() {
    int ans;
    scanf("%d %d %d", &N, &l, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &posc[i], &posr[i]);
    }
    ans = solve();
    printf("%d", ans);
    return 0;
}

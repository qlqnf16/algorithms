#include <stdio.h>
#define MAX 20

struct POS {
    int c, r;
};
int N, M, hcnt, ccnt, ans = 987897987;
int map[MAX+2][MAX+2];
POS houses[MAX*2];
POS chickens[14];
bool visit[14];

int abs(int num) {
    return num < 0 ? -num : num;
}

int calcChickenDist()  {
    int sum = 0, tempmin, tempdis;
    for (int i = 0; i < hcnt; i++) {
        tempmin = 987987;
        for (int j = 0; j < MAX; j++) {
            if (visit[j]) {
                tempdis = abs(houses[i].c - chickens[j].c) + abs(houses[i].r - chickens[j].r);
                if (tempdis < tempmin) tempmin = tempdis;
            }
        }
        sum += tempmin;
    }
    return sum;
}

void dfs(int n, int cnt) {
    if (cnt >= M) {
        int sum = calcChickenDist();
        if (sum < ans) ans = sum;
        return;
    }
    if (n >= ccnt) return;
    
    visit[n] = true;
    dfs(n+1, cnt+1);
    visit[n] = false;
    dfs(n+1, cnt);
}

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) {
                houses[hcnt].c = i;
                houses[hcnt].r = j;
                hcnt++;
             }
            if (map[i][j] == 2) {
                chickens[ccnt].c = i;
                chickens[ccnt].r = j;
                ccnt++;
            }
        }
    }
    dfs(0, 0);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    solve();
    printf("%d", ans);
    return 0;
}

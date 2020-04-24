#include <stdio.h>
#define MAXB 10
#define MAXP 100010

int B, N, ans;
int boats[MAXB];
int people[MAXP];
int peWeights[MAXP];
bool departed[MAXB];

int calcPeopleOnBoard(int boatWeight, int pi) {
    int s, e, m, ans;
    s = pi; e = N;
    while (s <= e) {
        m = (s+e) / 2;
        if (peWeights[m] - peWeights[pi-1] > boatWeight) e = m-1;
        else {
            ans = m;
            s = m+1;
        }
    }
    return ans+1;
}

void dfs(int n, int pi, int leftWeight) {
    if (pi > N) {
        if (leftWeight > ans) ans = leftWeight;
        return;
    }
    if (n >= B-1 || leftWeight < ans) return;
    
    for (int i = 0; i < B; i++) {
        if (departed[i]) continue;
        departed[i] = true;
        dfs(n+1, calcPeopleOnBoard(boats[i], pi), leftWeight-boats[i]);
        departed[i] = false;
    }
}

void calcRange() {
    peWeights[1] = people[1];
    for (int i = 2; i <= N; i++) {
        peWeights[i] = peWeights[i-1] + people[i];
    }
}

int main() {
    int totalWeight = 0;
    scanf("%d %d", &B, &N);
    for (int i = 0; i < B; i++) {
        scanf("%d", &boats[i]);
        totalWeight += boats[i];
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &people[i]);
    }
    calcRange();
    if (totalWeight < peWeights[N]) {
        printf("-1");
        return 0;
    }
    dfs(0, 1, totalWeight);
    
    printf("%d", ans);
    return 0;
}

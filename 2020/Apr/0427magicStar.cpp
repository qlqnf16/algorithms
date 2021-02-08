#include <stdio.h>

char map[5][10];
int C[] = {0, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4};
int R[] = {4, 1, 3, 5, 7, 2, 6, 1, 3, 5, 7, 4};
int line1[] = {0, 3, 0, 2, 4, 0, 2, 0, 1, 1, 1, 3};
int line2[] = {2, 5, 5, 5, 5, 3, 4, 1, 3, 4, 2, 4};

int emptyCnt;
int empty[12];
int used[13];
int sum[6];
int sumCnt[6];

int dfs(int n) {
    int c, r, l1, l2, idx;
    if (n >= emptyCnt) return 1;
    
    idx = empty[n];
    c = C[idx];
    r = R[idx];
    l1 = line1[idx];
    l2 = line2[idx];
    for (int i = 1; i <= 12; i++) {
        if (used[i]) continue;
        if (sumCnt[l1] >= 3) {
            if (sum[l1] + i != 26) continue;
        }
        else {
            if (sum[l1] + i >= 26) continue;
        }
        if (sumCnt[l2] >= 3) {
            if (sum[l2] + i != 26) continue;
        }
        else {
            if (sum[l2] + i >= 26) continue;
        }
        used[i] = 1;
        sum[l1] += i; sumCnt[l1]++;
        sum[l2] += i; sumCnt[l2]++;
        map[c][r] = 'A'+i-1;
        if (dfs(n+1)) return 1;
        used[i] = 0;
        sum[l1] -= i; sumCnt[l1]--;
        sum[l2] -= i; sumCnt[l2]--;
    }
    return 0;
}

void solve() {
    int val;
    for (int i = 0; i < 12; i++) {
        if (map[C[i]][R[i]] == 'x') {
            empty[emptyCnt++] = i;
        } else {
            val = map[C[i]][R[i]] - 'A' + 1;
            int l1 = line1[i];
            int l2 = line2[i];
            used[val] = 1;
            sum[l1] += val; sumCnt[l1] ++;
            sum[l2] += val; sumCnt[l2] ++;
        }
    }
    dfs(0);
}

void output() {
    for (int i = 0; i < 5; i++) {
        printf("%s\n", map[i]);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        scanf("%s", map[i]);
    }
    solve();
    output();
    return 0;
}

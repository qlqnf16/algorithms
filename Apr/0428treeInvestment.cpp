#include <stdio.h>
#include <deque>
#include <algorithm>
#define MAXN 12
using namespace std;

int N, M, K, totalTree; // 땅 넓이, 나무 수, K년 후
int land[MAXN][MAXN];
deque<int> trees[MAXN][MAXN];

int nutrients[MAXN][MAXN];
int dir[][8] = {{1, 1, 1, 0, 0, -1, -1, -1}, {-1, 0, 1, -1, 1, -1, 0, 1}};

void initialize() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            land[i][j] = 5;
        }
    }
}

void spring() {
    deque<int>::iterator tree;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (trees[i][j].empty()) continue;
            for (tree = trees[i][j].begin(); tree != trees[i][j].end(); tree++) {
                if (land[i][j] >= *tree) {
                    land[i][j] -= *tree;
                    (*tree) ++;
                } else {
                    (*tree) *= -1;
                }
            }
        }
    }
}

void summer() {
    int deadTotal = 0;
    deque<int>::reverse_iterator tree;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (trees[i][j].empty()) continue;
            deadTotal = 0;
            for (tree = trees[i][j].rbegin(); tree != trees[i][j].rend(); tree++) {
                if ((*tree) > 0) break;
                land[i][j] += ((*tree) * -1)/2;
                deadTotal ++;
            }
            for (int d = 0; d < deadTotal; d++) {
                trees[i][j].pop_back();
                totalTree--;
            }
        }
    }
}

void fall() {
    int nc, nr;
    deque<int>::iterator tree;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (trees[i][j].empty()) continue;
            for (tree = trees[i][j].begin(); tree != trees[i][j].end(); tree++) {
                if ((*tree) % 5) continue;
                for (int k = 0; k < 8; k++) {
                    nc = i + dir[0][k];
                    nr = j + dir[1][k];
                    if (nc < 1 || nc > N || nr < 1 || nr > N) continue;
                    trees[nc][nr].push_front(1);
                    totalTree++;
                }
            }
        }
    }
}

void winter() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            land[i][j] += nutrients[i][j];
        }
    }
}

void sortMap() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (trees[i][j].empty()) continue;
            sort(trees[i][j].begin(), trees[i][j].end());
        }
    }
}


int solve() {
    totalTree = M;
    initialize();
    sortMap();
    for (int i = 1; i <= K; i++) {
        spring();
        summer();
        fall();
        winter();
    }
    return totalTree;
}

int main() {
    int ans;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &nutrients[i][j]);
        }
    }
    for (int i = 0; i < M; i++) {
        int c, r, age;
        scanf("%d %d %d", &c, &r, &age);
        trees[c][r].push_back(age);
    }
    ans = solve();
    printf("%d", ans);
    
    return 0;
}

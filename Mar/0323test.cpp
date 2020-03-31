// 도약
#if 0
#include <cstdio>
#include <algorithm>
#define MAX 1010
using namespace std;

int n;
int leaves[MAX];

int binarySearch(int s, int target, bool greater) {
    int m, e = n-1;
    while (s <= e) {
        m = (s+e) / 2;
        if (leaves[m] == target) return m;
        if (leaves[m] > target) e = m - 1;
        else s = m + 1;
    }
    return greater ? s : e;
}

int findJump(int s) {
    int dist, start, end;
    int sum = 0;
    
    for (int i = s+1; i < n; i++) {
        dist = leaves[i] - leaves[s];
        start = binarySearch(i+1, leaves[i]+dist, true);
        end = binarySearch(i+1, leaves[i]+dist*2, false);
        
        if (end >= start) {
            sum += end - start + 1;
           // printf("%d - %d %d %d %d %d\n",s, leaves[i], dist, leaves[start], leaves[end], end);
        }
    }
    
    return sum;
}

int main() {
    int ans = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &leaves[i]);
    }
    sort(leaves, leaves+n);
    
    for (int i = 0; i < n; i++) {
        ans +=  findJump(i);
    }
    printf("%d", ans);
    
    return 0;
}
#endif

// 요플레 공장
#if 0
#include <cstdio>
#define MAX 10010
using namespace std;

int N, S; // S 유지비용
int C[MAX]; // 그 주 가격
int Y[MAX]; // 그 주 필요량
int price = 5000;
long long sum = 0;

int main() {
    scanf("%d %d", &N, &S);
    for (int i = 0;i < N; i++) {
        scanf("%d %d", &C[i], &Y[i]);
    }
    
    for (int i = 0; i < N; i++) {
        price += S;
        if (price > C[i]) price = C[i];
        sum += price * Y[i];
    }
    printf("%lld", sum);

    return 0;
}
#endif

// 안전 영역
#if 0
#include <cstdio>
#include <queue>
#define MAX 110
using namespace std;

int n;
int map[MAX][MAX];
bool visit[MAX][MAX];

int dir[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
queue<int> colQueue;
queue<int> rowQueue;

void bfs(int c, int r, int height) {
    int nc, nr;
    colQueue.push(c);
    rowQueue.push(r);
    visit[c][r] = true;
    
    while (!colQueue.empty()) {
        c = colQueue.front();
        r = rowQueue.front();
        colQueue.pop();
        rowQueue.pop();
        
        for (int i = 0; i < 4; i ++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            if (nc < 0 || nc >= n || nr < 0 || nr >= n) continue;
            if (!visit[nc][nr] && map[nc][nr] > height) {
                visit[nc][nr] = true;
                colQueue.push(nc);
                rowQueue.push(nr);
            }
        }
    }
}

void initArray() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            visit[i][j] = false;
        }
    }
}

int main() {
    int cnt, ans = 0, maxHeight = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] > maxHeight) maxHeight = map[i][j];
        }
    }
    
    for (int h = 0; h <= maxHeight; h++) {
        cnt = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j] && map[i][j] > h) {
                    bfs(i, j, h);
                    cnt ++;
                }
            }
        }
        initArray();
        
        if (cnt > ans) {
            ans = cnt;
        }
    }
    
    printf("%d", ans);
    
    
    return 0;
}
#endif

// 드래곤 던전
#if 0
#include <cstdio>
#include <queue>
#define MAX 40
using namespace std;

typedef struct {
    int l;
    int c;
    int r;
} position;

int L, C, R;
char map[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int route[MAX][MAX][MAX];

int dir[3][6] = { {0,0,0,0,1,-1}, {0,0,1,-1,0,0},{1,-1,0,0,0,0}};
int sc, sr, sl;
int ec, er, el;

int bfs(int l, int c, int r) {
    int nl, nc, nr;
    queue<position> posQueue;
    posQueue.push({l, c, r});
    visit[l][c][r] = true;
    
    while (!posQueue.empty()) {
        l = posQueue.front().l;
        c = posQueue.front().c;
        r = posQueue.front().r;
        posQueue.pop();
        if (map[l][c][r] == 'E') return route[l][c][r];
        
        for (int i = 0; i < 6; i++) {
            nl = l + dir[0][i];
            nc = c + dir[1][i];
            nr = r + dir[2][i];
            
            if (nc < 0 || nc >= C || nr < 0 || nr >= R || nl < 0 || nl >= L) continue;
            if (!visit[nl][nc][nr] && map[nl][nc][nr] != '#') {
                visit[nl][nc][nr] = true;
                route[nl][nc][nr] = route[l][c][r] + 1;
                posQueue.push({nl, nc, nr});
            }
        }
    }
    
    return 0;
}

void initArray() {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = 0; k < R; k++) {
                visit[i][j][k] = false;
                route[i][j][k] = 0;
            }
        }
    }
}

int main() {
    int time;
    while(true) {
        scanf("%d %d %d", &L, &C, &R);
        if (L == 0 && R == 0 && C == 0) return 0;
        
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%s", map[i][j]);
                for (int k = 0; k < R; k++) {
                    if (map[i][j][k] == 'S') {
                        sl = i; sc = j; sr = k;
                    }
                }
            }
            getchar();
        }
        
        time = bfs(sl, sc, sr);
        if (!time) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", time);
        initArray();
    }
    
    return 0;
}
#endif

// 먼 목초지
#if 0
#include <cstdio>
#include <queue>
#define MAX 35
using namespace std;

int N;
long long A, B;
long long route[MAX][MAX];
char map[MAX][MAX];

int dir[2][4] = {{0,0,-1,1}, {1,-1,0,0}};
queue<int> colQueue;
queue<int> rowQueue;
long long  ans;

void bfs(int c, int r) {
    int nc, nr;
    long long dist;
    colQueue.push(c);
    rowQueue.push(r);
    
    while (!colQueue.empty()) {
        c = colQueue.front();
        r = rowQueue.front();
        colQueue.pop();
        rowQueue.pop();
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            
            if (nc < 0 || nc >= N || nr < 0 || nr >= N) continue;
            dist = (map[nc][nr] == map[c][r]) ? A : B;
            if (route[c][r] + dist < route[nc][nr]) {
                route[nc][nr] = route[c][r] + dist;
                colQueue.push(nc);
                rowQueue.push(nr);
            }
        }
    }
}

void initArray() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            route[i][j] = 987987987;
        }
    }
}

void findMax() {
    long long temp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (temp < route[i][j]) temp = route[i][j];
        }
    }
    if (temp > ans) ans = temp;
}

int main() {
    scanf("%d %lld %lld", &N, &A, &B);
    for (int i = 0; i < N; i++) {
        scanf("%s", map[i]);
    }
    
    for (int i =0; i < N; i++) {
        for (int j = 0; j < N; j++){
            initArray();
            route[i][j] = 0;
            bfs(i, j);
            findMax();
        }
    }
    printf("%lld", ans);
    
    
    return 0;
}
#endif

// 최고의 수식을 찾아라
#if 0
#include <cstdio>
using namespace std;

int N, A; // A- 항 하나당 추가가치
int Wi[7]; // 4개 이하 가치
int Vi[7]; // 5개 이상 가치
int used[7];
int value[7] = {1,2,4,8,16,32,64};
int sol;
int finalUse[7];

int calcFinalValue() {
    int sum = 0, cnt = 0;
    for (int i = 0; i < 7; i++) {
        if (used[i] >= 5) sum += Vi[i] * used[i];
        else sum += Wi[i] * used[i];
        cnt += used[i];
    }
    sum += cnt * A;
    return sum;
}

void copyArray() {
    for (int i = 0; i < 7; i++) {
        finalUse[i] = used[i];
    }
}

void dfs(int n, int sum) {
    int fin;
    if (sum > N) return;
    if (sum == N) {
        fin = calcFinalValue();
        if (fin > sol) {
            sol = fin;
            copyArray();
        }
        return;
    }
    
    for (int i = n; i < 7; i++) {
        if (sum + value[i] <= N) {
            used[i] ++;
            dfs(i, sum + value[i]);
            used[i] --;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < 7; i++) {
        scanf("%d", &Wi[i]);
    }
    for (int i = 0; i < 7; i++) {
        scanf("%d", &Vi[i]);
    }
    scanf("%d", &A);
    dfs(0,0);
    printf("%d\n", sol);
    for (int i = 0; i< 7; i++) printf("%d ", finalUse[i]);
    
    return 0;
}
#endif

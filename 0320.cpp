// 영역구하기
#if 0
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX 110
using namespace std;

int m, n, k;
int map[MAX][MAX];
bool visit[MAX][MAX];
int areas[MAX*MAX];
int dir[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

void bfs(int c, int r, int idx) {
    int nc, nr;
    queue<int> colQueue;
    queue<int> rowQueue;
    colQueue.push(c);
    rowQueue.push(r);
    visit[c][r] = true;
    
    while (!colQueue.empty()) {
        c = colQueue.front();
        r = rowQueue.front();
        colQueue.pop();
        rowQueue.pop();
        areas[idx] ++;
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            if ((nc >= 0 && nc < m && nr >= 0 && nr < n) && !visit[nc][nr] && !map[nc][nr]) {
                colQueue.push(nc);
                rowQueue.push(nr);
                visit[nc][nr] = true;
            }
        }
    }
}

int main() {
    int idx = 0;
    
    scanf("%d %d %d", &m, &n, &k);
    for (int t = 0; t < k; t++) {
        int lx, ly, rx, ry;
        scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
        for (int i = m-ry; i < m-ly; i++) {
            for (int j = lx; j < rx; j++) {
                map[i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j] && !map[i][j]) bfs(i, j, idx++);
        }
    }
    
    
    printf("%d\n", idx);
    sort(areas, areas+idx);
    for (int i = 0; i < idx; i++) {
        printf("%d ", areas[i]);
    }
    
    return 0;
}
#endif

// 보너스
#if 0
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 11
using namespace std;

int n, m;
int bonus[MAX];
int workers[MAX];
vector<int> relation[MAX];
bool given[MAX];
bool success;

bool check(int id, int bi) {
    int next;
    for (int i = 0; i < relation[id].size(); i++) {
        next = relation[id][i];
        if (next < 0) {
            // id가 상급자보다 많은 보너스를 받는지
            if (workers[-next] && workers[-next] <= bonus[bi]) return false;
        }
        else {
            // id가 하급자보다 더 적은 보너스를 받는지
            if (workers[next] && workers[next] >= bonus[bi]) return false;
        }
    }
    return true;
}

void dfs(int id) {
    if (id > n) {
        success = true;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (given[i] || !check(id, i)) continue;
        workers[id] = bonus[i];
        given[i] = true;
        dfs(id+1);
        
        if (success) return;
        
        workers[id] = 0;
        given[i] = false;
    }
}

int desc(int a, int b){
    return a > b;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        relation[a].push_back(b);
        relation[b].push_back(-a);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &bonus[i]);
    }
    sort(bonus, bonus+n, desc);
    dfs(1);
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", workers[i]);
    }
    
    return 0;
}
#endif

// 공주님의 정원
#if 0
#include <cstdio>
#include <algorithm>
#define MAX 100010
using namespace std;

typedef struct {
    int month;
    int day;
} date;

struct st {
    date start;
    date end;
} flowers[MAX];
int n, cnt;
date fromTarget = {3,1};
date toTarget = {11, 30};

int isLateThan(date a, date b) {
    if (a.month > b.month) return 1;
    if (a.month == b.month) {
        if (a.day > b. day) return 1;
        if (a.day == b.day) return 0;
        return -1;
    }
    return -1;
}

bool compare(const st& a, const st& b) {
    int temp = isLateThan(a.start, b.start);
    if (temp == -1) return true;
    if (temp == 0) {
        if (isLateThan(a.end, b.end) == -1) return true;
        return false;
    }
    return false;
}

void solve() {
    date from = fromTarget;
    date to = {1,1};
    int startIndex = 0;
    
    while (isLateThan(to, toTarget) <= 0) {
        for (int i = startIndex; i < n; i++) {
            if (isLateThan(flowers[i].start, from) == 1) {
                startIndex = i;
                break;
            }
            if (isLateThan(flowers[i].end, to) == 1) {
                to = flowers[i].end;
                if (isLateThan(to, toTarget) == 1) break;
            }
        }
        from = to;
        cnt ++;
    }
}

int main() {
    date minD = {12,31}, maxD = {1,1};
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &flowers[i].start.month, &flowers[i].start.day);
        scanf("%d %d", &flowers[i].end.month, &flowers[i].end.day);
        if (isLateThan(flowers[i].start, minD) == -1) minD = flowers[i].start;
        if (isLateThan(flowers[i].end, maxD) == 1) maxD = flowers[i].end;
    }
    
    if (isLateThan(minD, fromTarget) == 1 || isLateThan(maxD, toTarget) <= 0) {
        printf("%d", cnt);
        return 0;
    }
    
    sort(flowers, flowers+n, compare);
    solve();
    printf("%d", cnt);
    
    return 0;
}

#endif


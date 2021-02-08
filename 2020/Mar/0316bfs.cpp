// codexpert - 저글링 방사능 오염
#if 0
#include <cstdio>
#include <queue>
#define MAX 100

using namespace std;
int w, h;
int map[MAX][MAX];
int dir[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
bool visit[MAX][MAX];

int bfs(int sc, int sr) {
    int c, r, nc, nr, cnt = 0;
    
    queue<int> columnQueue;
    queue<int> rowQueue;
    
    columnQueue.push(sc);
    rowQueue.push(sr);
    visit[sc][sr] = true;
    map[sc][sr] = 3;
    
    while (!columnQueue.empty()) {
        c = columnQueue.front();
        r = rowQueue.front();
        columnQueue.pop();
        rowQueue.pop();
        cnt = map[c][r];
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            
            if ((nc >= 0 && nc < h && nr >= 0 && nr < w) && map[nc][nr] && !visit[nc][nr]) {
                columnQueue.push(nc);
                rowQueue.push(nr);
                visit[nc][nr] = true;
                map[nc][nr] = map[c][r] + 1;
            }
        }
    }
    
    return cnt;
}

int main(){
    int sc, sr, ans, remainCnt = 0;
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    scanf("%d %d", &sr, &sc);
    
    ans = bfs(sc-1, sr-1);
    printf("%d\n", ans);
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] == 1) remainCnt ++;
        }
    }
    printf("%d", remainCnt);
    
    return 0;
}
#endif

// 2색칠하기
#if 0
#include <cstdio>
#include <vector>
#include <queue>
#define MAX 10010

using namespace std;

int n, m;
bool possible;
vector<int> graph[MAX];
int color[MAX];
bool visit[MAX];

bool bfs(int start) {
    int x, y;
    
    queue<int> myQueue;
    myQueue.push(start);
    visit[start] = true;
    color[start] = 1;
    
    while (!myQueue.empty()) {
        x = myQueue.front();
        myQueue.pop();
        
        for (int i = 0; i < graph[x].size(); i++) {
            y = graph[x][i];
            if (!visit[y]) myQueue.push(y);
            if (color[y] == color[x]) return false;
            color[y] = color[x] * -1;
            visit[y] = true;
        }
    }
    
    return true;
}

int main(){
    bool ans;
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    ans = bfs(0);
    printf(ans ? "YES" : "NO");
    
    return 0;
}
#endif

// 웜바이러스
#if 0
#include <cstdio>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

int n, m, cnt;
vector<int> graph[MAX];
bool visit[MAX];

void bfs(int start) {
    int x, y;
    queue<int> comQueue;
    comQueue.push(start);
    visit[start] = true;
    
    while (!comQueue.empty()) {
        x = comQueue.front();
        comQueue.pop();
        
        for (int i = 0; i < graph[x].size(); i++) {
            y = graph[x][i];
            if (!visit[y]) {
                comQueue.push(y);
                visit[y] = true;
                cnt ++;
            }
        }
    }
}

int main(){
    scanf("%d\n%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    printf("%d", cnt);
    return 0;
}
#endif

// 미로찾기
#if 0
#include <cstdio>
#include <queue>
#define MAX 1000

using namespace std;
int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dir[2][4] = {{0,0,1,-1},{1,-1,0,0}};
void bfs(int sc, int sr) {
    int c, r, nc, nr;
    queue<int> colQueue;
    queue<int> rowQueue;
    
    colQueue.push(sc);
    rowQueue.push(sr);
    visit[sc][sr] = true;
    
    while (!colQueue.empty()) {
        c = colQueue.front();
        r = rowQueue.front();
        colQueue.pop();
        rowQueue.pop();
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            
            if ((nc >= 0 && nc < n && nr >= 0 && nr < m) && !map[nc][nr] && !visit[nc][nr]) {
                visit[nc][nr] = true;
                colQueue.push(nc);
                rowQueue.push(nr);
                map[nc][nr] = map[c][r] + 1;
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    bfs(n-1, 0);
    return 0;
}
#endif

// 단지번호 붙이기
#if 0
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAX 25

using namespace std;
int n;
int map[MAX][MAX];
int houses[MAX*MAX];
int dir[2][4] = {{0, 0, -1, 1}, {1, -1, 0, 0}};
bool visit[MAX][MAX];

void bfs(int sc, int sr, int idx) {
    int c, r, nc, nr, cnt = 0;
    queue<int> colQueue;
    queue<int> rowQueue;
    
    colQueue.push(sc);
    rowQueue.push(sr);
    visit[sc][sr] = true;
    
    while (!colQueue.empty()) {
        c = colQueue.front();
        r = rowQueue.front();
        colQueue.pop();
        rowQueue.pop();
        cnt ++;
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            
            if ((nc >= 0 && nc < n && nr >= 0 && nr < n) && map[nc][nr] && !visit[nc][nr]) {
                visit[nc][nr] = true;
                colQueue.push(nc);
                rowQueue.push(nr);
            }
        }
    }
    
    houses[idx] = cnt;
}

int main(){
    int houseCnt = 0;
    scanf("%d", &n);
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] && !visit[i][j]) bfs(i, j, houseCnt++);
        }
    }
    
    sort(houses, houses+houseCnt);
    printf("%d\n", houseCnt);
    for (int i = 0; i < houseCnt; i ++) {
        printf("%d\n", houses[i]);
    }
    return 0;
}
#endif

// 이상한 계산기
#if 0
#include <cstdio>
#include <queue>
#define MAX 100000

using namespace std;
int goal;
int counts[MAX];
bool visit[MAX];

void bfs() {
    int n, mul, div;
    queue<int> numQueue;
    numQueue.push(1);
    visit[1] = true;
    
    while (!numQueue.empty()) {
        n = numQueue.front();
        numQueue.pop();
        if (n == goal) return;
        mul = n * 2;
        div = n / 3;
        
        if (!visit[mul] && mul <= 99999) {
            counts[mul] = counts[n] + 1;
            numQueue.push(mul);
            visit[mul] = true;
        }
        if (!visit[div] && div != 0 && mul != div) {
            counts[div] = counts[n] + 1;
            numQueue.push(div);
            visit[div] = true;
        }
    }
}

int main(){
    scanf("%d", &goal);
    bfs();
    printf("%d", counts[goal]);
    return 0;
}
#endif

// 전염병
#if 0
#include <cstdio>
#include <queue>
#define MAX 100010

using namespace std;
int n;
bool visit[MAX];

void bfs(int start){
    int now, mul, div;
    
    queue<int> numQueue;
    numQueue.push(start);
    visit[start] = true;
    
    while (!numQueue.empty()) {
        now = numQueue.front();
        numQueue.pop();
        
        mul = now * 2;
        div = now / 3;
        if (mul <= n && !visit[mul]) {
            visit[mul] = true;
            numQueue.push(mul);
        }
        if (div > 0 && !visit[div]) {
            visit[div] = true;
            numQueue.push(div);
        }
    }
}

int main() {
    int k, cnt = 0;
    scanf("%d %d", &n, &k);
    bfs(k);
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) cnt ++;
    }
    printf("%d", cnt);
    return 0;
}
#endif

// 목수의 미로탈출
#if 0
#include <cstdio>
#include <queue>
#define MAX 1000

using namespace std;

int n, m;
int map[MAX][MAX];
int dist[MAX][MAX];
int distReverse[MAX][MAX];
bool visit[MAX][MAX];
bool visitReverse[MAX][MAX];
bool rev;

int dir[2][4] = {{0,0,-1,1}, {-1,1,0,0}};

void bfs(int c, int r) {
    int nc, nr;
    queue<int> colQueue;
    queue<int> rowQueue;
    colQueue.push(c);
    rowQueue.push(r);
    
    rev ? visitReverse[c][r] = true : visit[c][r] = true;
    
    while (!colQueue.empty()) {
        c = colQueue.front();
        r = rowQueue.front();
        colQueue.pop();
        rowQueue.pop();
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            
            if (nc >= 0 && nc < n && nr >= 0 && nr < m) {
                if (rev) {
                    if (!visitReverse[nc][nr] && !map[nc][nr]) {
                        visitReverse[nc][nr] = true;
                        distReverse[nc][nr] = distReverse[c][r] + 1;
                        colQueue.push(nc);
                        rowQueue.push(nr);
                    }
                }
                else {
                    if (!visit[nc][nr] && !map[nc][nr]) {
                        visit[nc][nr] = true;
                        dist[nc][nr] = dist[c][r] + 1;
                        colQueue.push(nc);
                        rowQueue.push(nr);
                    }
                }
            }
        }
    }
}

int countDistance(int c, int r) {
    int nc, nr, min, minRev;
    min = minRev = 987987987;
    
    for (int i = 0; i < 4; i ++) {
        nc = c + dir[0][i];
        nr = r + dir[1][i];
        
        if (nc >= 0 && nc < n && nr >= 0 && nr < m) {
            if (dist[nc][nr] && dist[nc][nr] < min) min = dist[nc][nr];
            if (distReverse[nc][nr] && distReverse[nc][nr] < minRev) minRev = distReverse[nc][nr];
        }
    }
    
    return min + minRev;
}

int main() {
    int tempDist, sum = 987987987;
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    bfs(n-1, 0);
    rev = 1;
    bfs(0, m-1);
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j]) {
                tempDist = countDistance(i, j);
                if (tempDist < sum) sum = tempDist;
            }
        }
    }
    
    printf("%d", sum + 2);
    return 0;
}
#endif

// 보물섬
#if 0
#include <cstdio>
#include <queue>
#define MAX 60

using namespace std;

int n, m;
char map[MAX][MAX];
int route[MAX][MAX];
bool visit[MAX][MAX];

int dir[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
queue<int> colQueue;
queue<int> rowQueue;

void initArray() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            route[i][j] = 0;
            visit[i][j] = false;
        }
    }
}

int bfs(int c, int r) {
    int max = 0, nc, nr;
    colQueue.push(c);
    rowQueue.push(r);
    visit[c][r] = true;
    
    while (!colQueue.empty()) {
        c = colQueue.front();
        r = rowQueue.front();
        colQueue.pop();
        rowQueue.pop();
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            
            if (nc < 0 || nc >= n || nr < 0 || nr >= m) continue;
            if (!visit[nc][nr] && map[nc][nr] == 'L') {
                visit[nc][nr] = true;
                route[nc][nr] = route[c][r] + 1;
                colQueue.push(nc);
                rowQueue.push(nr);
                if (route[nc][nr] > max) max = route[nc][nr];
            }
        }
    }
    
    return max;
}

int main() {
    int dist, ans = 0;
    char input;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%c", &input);
            if (j > 0) map[i][j-1] = input;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L') {
                dist = bfs(i, j);
                if (ans < dist) ans = dist;
                initArray();
            }
        }
    }
    
    printf("%d", ans);
    
    return 0;
}

#endif

// 귀가
#if 0
#include <cstdio>
#include <vector>
#define MAX 10010

using namespace std;

int n;
vector<int> graph[200];
vector<int> dist[200];
int minDist[MAX];
bool visit[MAX];

void dijkstra() {
    int tempMin, minIndex, node, tempDist;
    minDist[90] = 0;
    
    for (int i = 0; i < n; i++) {
        tempMin = 987987987;
        minIndex = -1;
        
        for (int j = 65; j < 123; j++) {
            if (!graph[j].size()) continue;
            if (!visit[j] && tempMin > minDist[j]) {
                tempMin = minDist[j];
                minIndex = j;
            }
        }
        visit[minIndex] = true;
        
        for (int j = 0; j < graph[minIndex].size(); j++) {
            node = graph[minIndex][j];
            tempDist = dist[minIndex][j];
            if (minDist[node] > minDist[minIndex] + tempDist) {
                minDist[node] = minDist[minIndex] + tempDist;
            }
        }
    }
}

void initMinDist() {
    for (int i = 65; i < 123; i++) {
        minDist[i] = 987987987;
    }
}

int main() {
    char i1, i2; int a1, a2, d;
    int tempMin = 987987, minIndex = 65;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("\n%c %c %d", &i1, &i2, &d);
        a1 = int(i1);
        a2 = int(i2);
        
        graph[a1].push_back(a2);
        graph[a2].push_back(a1);
        dist[a1].push_back(d);
        dist[a2].push_back(d);
    }

    initMinDist();
    dijkstra();
    
    for (int m = 65; m < 90; m++) {
        if (minDist[m] < tempMin) {
            tempMin = minDist[m];
            minIndex = m;
        }
    }
    printf("%c %d", char(minIndex), tempMin);
    
    
    return 0;
}

#endif

// 암소 미인 대회
#if 0
#include <cstdio>
#include <queue>
#define MAX 50 + 10

using namespace std;

int n, m;
char pattern[MAX][MAX];
int area[MAX][MAX];
int dist[MAX][MAX];
bool visit[MAX][MAX];
int dir[2][4] = {{0,0,1,-1}, {1,-1,0,0}};

int bfs(int c, int r, int num) {
    int nc, nr;
    
    queue<int> colQueue;
    queue<int> rowQueue;
    colQueue.push(c);
    rowQueue.push(r);
    visit[c][r] = true;
    area[c][r] = num;
    
    while (!colQueue.empty()) {
        c = colQueue.front();
        r = rowQueue.front();
        colQueue.pop();
        rowQueue.pop();
        
        for (int i = 0; i < 4; i++) {
            nc = c + dir[0][i];
            nr = r + dir[1][i];
            
            if (nc < 0 || nc >= n || nr < 0 || nr >= m) continue;
            if (num) {
                if (!visit[nc][nr] && pattern[nc][nr] == 'X') {
                    visit[nc][nr] = true;
                    area[nc][nr] = num;
                    colQueue.push(nc);
                    rowQueue.push(nr);
                }
            }
            else {
                if (!visit[nc][nr] && area[nc][nr] != 1) {
                    visit[nc][nr] = true;
                    if (area[nc][nr] == 2) return dist[c][r];
                    dist[nc][nr] = dist[c][r] + 1;
                    colQueue.push(nc);
                    rowQueue.push(nr);
                }
            }
        }
    }
    
    return 0;
}

void devideArea() {
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j] && pattern[i][j] == 'X') bfs(i, j, num ++);
        }
    }
}

void initArray() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = false;
            dist[i][j] = 0;
        }
    }
}

int main() {
    int ans = 987987, temp; char input;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%c", &input);
            if (j) pattern[i][j-1] = input;
        }
    }
    devideArea();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (area[i][j] == 1) {
                initArray();
                temp = bfs(i, j, 0);
                if (temp && temp < ans) ans = temp;
            }
        }
    }
    
    printf("%d", ans);
    
    
    return 0;
}

#endif

// 벽장문의 이동
#if 0
#include <cstdio>
#define MAX 20 + 10

using namespace std;
int n, m;
int openCloset[2];
int useQueue[MAX];
int ans = 987987;

int abs(int n) {
    if (n >= 0) return n;
    return -n;
}

int dfs(int id, int cnt) {
    int want, temp;
    if (id >= m) {
        if (ans > cnt) ans = cnt;
        return 1;
    }
    if (ans < cnt) return 0;
    
    want = useQueue[id];
    for (int i = 0; i < 2; i++) {
        temp = openCloset[i];
        openCloset[i] = want;
        dfs(id+1, cnt + abs(temp - want));
        openCloset[i] = temp;
    }
    
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2; i++) {
        scanf("%d", &openCloset[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &useQueue[i]);
    }
    dfs(0, 0);
    printf("%d", ans);
    
    return 0;
}
#endif

// 기업투자
#if 0
#include <cstdio>
#include <algorithm>

using namespace std;
int seed, company, ans;
int profits[40][10];
int money[10];
int ansMoney[10];

void dfs(int c, int left, int sum) {
    if (c > company) {
        if (sum > ans) {
            copy(money, money+company+1, ansMoney);
            ans = sum;
        }
        return;
    }

    for (int i = 0; i <= left; i++) {
        money[c] = i;
        dfs(c+1, left - i, sum + profits[i][c]);
    }
}

int main() {
    int a;
    
    scanf("%d %d", &seed, &company);
    for (int i = 0; i < seed; i++) {
        scanf("%d", &a);
        for (int j = 1; j <= company; j++) {
            scanf("%d", &profits[a][j]);
        }
    }
    
    dfs(1, seed, 0);
    printf("%d\n", ans);
    for(int i = 1; i <= company; i++) {
        printf("%d ", ansMoney[i]);
    }
    
    return 0;
}
#endif

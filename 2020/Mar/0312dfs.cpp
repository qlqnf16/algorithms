// 농장 탈출
#if 0
#include <cstdio>
using namespace std;

int n;
int weights[MAX];
int maxCount = -1;

int checkSum(int sum, int num) {
    while (sum > 0 && num > 0) {
        if ((sum % 10 + num % 10) > 9) return 0;
        sum /= 10;
        num /= 10;
    }
    return 1;
}

void DFS(int x, int sum, int count) {
    if (count > maxCount) maxCount = count;
    if (x >= n) return;
    
    if (checkSum(sum, weights[x])) DFS(x+1, sum+weights[x], count+1);
    DFS(x+1, sum, count);
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    
    DFS(0, 0, 0);
    printf("%d", maxCount);

    return 0;
}
#endif

// 두색칠하기, 이분그래프 판별
#if 0
#include <cstdio>
#include <vector>
using namespace std;
#define MAX 10001

int n, m;
vector<int> graph[MAX];
bool visited[MAX];
int color[MAX];
bool canPaint = true;

void dfs(int x, int prev) {
    prev *= -1;
    visited[x] = true;
    color[x] = prev;
    
    for (int i = 0; i < graph[x].size(); i++) {
        if (color[graph[x][i]] == prev) {
            canPaint = false;
            return;
        }
        if (!visited[graph[x][i]]) dfs(graph[x][i], prev);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(0, 1);
    printf(canPaint ? "YES" : "NO");
}

#endif

// 웜바이러스
#if 0
#include <cstdio>
#include <vector>
using namespace std;

#define MAX 101
int n, m, cnt = -1;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int x) {
    visited[x] = true;
    cnt ++;
    
    for (int i = 0; i < graph[x].size(); i++) {
        if (!visited[graph[x][i]]) dfs(graph[x][i]);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    printf("%d", !cnt ? 0 : cnt);
    
    return 0;
}
#endif

// 단지번호 붙이기
#if 0
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 25
#define MAXTOWN 1000

int n;
int map[MAX][MAX];
int houses[MAXTOWN];
bool visited[MAX][MAX];
int houseCount;
int dir[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};

void dfs(int prevC, int prevR) {
    int c, r;
    visited[prevC][prevR] = true;
    houseCount ++;
    
    for (int i = 0; i < 4; i ++) {
        c = prevC + dir[0][i];
        r = prevR + dir[1][i];
        if ((c >= 0 && c < n && r >= 0 && r < n) && !visited[c][r] && map[c][r] == 1) {
            dfs(c, r);
        }
    }
}

int main() {
    int hi = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] && !visited[i][j]) {
                dfs(i, j);
                houses[hi++] = houseCount;
                houseCount = 0;
            }
        }
    }
    
    sort(houses, houses+hi);
    printf("%d\n", hi);
    for (int i = 0; i < hi; i ++) {
        printf("%d\n", houses[i]);
    }
    
    return 0;
}
#endif

// 깊이우선탐색과 너비우선탐색
#if 01
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1010


int n, m;
vector<int> graph[MAX];
bool visited[MAX];
bool visitedBFS[MAX];

void dfs(int x){
    int next;
    
    printf("%d ", x);
    visited[x] = true;
    
    for (int i = 0; i < graph[x].size(); i++) {
        next = graph[x][i];
        if (!visited[next]) dfs(next);
    }
}

void bfs() {
    int current, next;
    queue<int> Queue;
    
    visitedBFS[0] = true;
    Queue.push(0);
    
    while (!Queue.empty()) {
        current = Queue.front();
        Queue.pop();
        printf("%d ", current);
        
        for (int i = 0; i < graph[current].size(); i++) {
            next = graph[current][i];
            if (!visitedBFS[next]) {
                visitedBFS[next] = true;
                Queue.push(next);
            }
        }
        
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(0);
    printf("\n");
    bfs();
    
    return 0;
}
#endif

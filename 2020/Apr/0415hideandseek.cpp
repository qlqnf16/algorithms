#include <cstdio>
#include <queue>
#define MAX 100010
using namespace std;

int fromLoc, toLoc;
int route[MAX];
bool visit[MAX];

void bfs(int x) {
    int nx;
    queue<int> xQueue;
    xQueue.push(x);
    visit[x] = true;
    
    while (!xQueue.empty()) {
        x = xQueue.front();
        xQueue.pop();
        if (x == toLoc) return;
        
        nx = x + 1;
        if (nx < MAX && !visit[nx]) {
            visit[nx] = true;
            route[nx] = route[x] + 1;
            xQueue.push(nx);
        }
        nx = x - 1;
        if (nx >= 0 && !visit[nx]) {
            visit[nx] = true;
            route[nx] = route[x] + 1;
            xQueue.push(nx);
        }
        nx = x * 2;
        if (nx < MAX && !visit[nx]) {
            visit[nx] = true;
            route[nx] = route[x] + 1;
            xQueue.push(nx);
        }
    }
}

int main() {
    scanf("%d %d", &fromLoc, &toLoc);
    bfs(fromLoc);
    printf("%d", route[toLoc]);
    return 0;
}

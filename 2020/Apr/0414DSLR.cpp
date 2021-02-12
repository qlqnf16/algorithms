#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define MAX 9999

typedef struct st {
    int num;
    string order;
} history;
int T;
int fromnum, tonum;
bool visit[MAX+1];
string answer;

void bfs(int from) {
    int next;
    history current;
    queue<history> hisQueue;
    hisQueue.push({from,""});
    visit[from] = true;
    
    while (!hisQueue.empty()) {
        current = hisQueue.front();
        hisQueue.pop();
        if (current.num == tonum) {
            printf("%s\n", current.order.c_str());
            return;
        }
        
        next = (current.num * 2) % 10000;
        if (!visit[next]) {
            hisQueue.push({next, current.order + "D"});
            visit[next] = true;
        }
        next = current.num ? current.num - 1 : MAX;
        if (!visit[next]) {
            hisQueue.push({next, current.order + "S"});
            visit[next] = true;
        }
        next = (current.num % 1000) * 10 + current.num / 1000;
        if (!visit[next]) {
            hisQueue.push({next, current.order + "L"});
            visit[next] = true;
        }
        next = (current.num % 10) * 1000 + current.num / 10;
        if (!visit[next]) {
            hisQueue.push({next, current.order + "R"});
            visit[next] = true;
        }
    }
}

int main(void) {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &fromnum, &tonum);
        bfs(fromnum);
        memset(visit, false, sizeof(visit));
    }
    
    return 0;
}

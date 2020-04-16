#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 100010

typedef struct {
    int start;
    int end;
} meet;
int N;
meet meetings[MAX];

bool compare(meet a, meet b) {
    if (a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

void solve() {
    int currentEnd = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (meetings[i].start < currentEnd) continue;
        currentEnd = meetings[i].end;
        ans ++;
    }
    printf("%d", ans);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }
    sort(meetings, meetings+N, compare);
    solve();
    return 0;
}

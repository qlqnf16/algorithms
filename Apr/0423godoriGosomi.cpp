#include <stdio.h>
#define MAX 30

int N;
int doc, dor, hdoc, hdor;
int soc, sor, hsoc, hsor;
int map[MAX][MAX];
int visit[MAX][MAX][MAX][MAX];
int dc[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dr[] = {0, -1, 1, 0, -1, 1, 0, -1, 1};

struct q {
    int doc;
    int dor;
    int soc;
    int sor;
    int t;
};
q que[1000000];
int wp, rp;

q front();
bool empty();
void push(int doc, int dor, int soc, int sor, int t);

int bfs() {
    int ndoc, ndor, nsoc, nsor;
    push(doc, dor, soc, sor, 0);
    while (!empty()) {
        q cur = front();
        if (cur.doc == hdoc && cur.dor == hdor && cur.soc == hsoc && cur.sor == hsor) return cur.t;
        
        for (int i = 0; i < 9; i++) {
            ndoc = cur.doc + dc[i];
            ndor = cur.dor + dr[i];
            if (ndoc < 0 || ndoc >= N || ndor < 0 || ndor >= N) continue;
            if (map[ndoc][ndor]) continue;
            for (int j = 0; j < 9; j++) {
                nsoc = cur.soc + dc[j];
                nsor = cur.sor + dr[j];
                if (nsoc < 0 || nsoc >= N || nsor < 0 || nsor >= N) continue;
                if (map[nsoc][nsor]) continue;
                push(ndoc, ndor, nsoc, nsor, cur.t+1);
            }
        }
    }
    
    return -1;
}

int solve() {
    return 0;
}

int main() {
    int ans;
    scanf("%d", &N);
    scanf("%d %d %d %d", &doc, &dor, &hdoc, &hdor);
    scanf("%d %d %d %d", &soc, &sor, &hsoc, &hsor);
    doc--; dor--; hdoc--; hdor--; soc--; sor--; hsoc--; hsor--;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    ans = bfs();
    printf("%d", ans);
}

q front() {
    return que[rp++];
}

bool empty() {
    return rp == wp;
}

void push(int doc, int dor, int soc, int sor, int t) {
    if (visit[doc][dor][soc][sor]) return;
    for (int i = 0; i < 9; i++) {
        if (soc + dc[i] == doc && sor + dr[i] == dor) return;
    }
    
    visit[doc][dor][soc][sor] = true;
    que[wp].doc = doc; que[wp].dor = dor;
    que[wp].soc = soc; que[wp].sor = sor; que[wp].t = t;
    wp++;
}

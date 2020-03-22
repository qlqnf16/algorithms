// 로봇 JUNG 1006
#if 0
#include <cstdio>
#include <queue>
#define MAX 110

using namespace std;

typedef struct {
    int c; int r; int d; int t;
} position;

int m, n;
int map[MAX][MAX];
bool visit[MAX][MAX][5];

int dir[2][5] = {{0,0,0,1,-1}, {0,1,-1,0,0}}; //-동서남북
int sc, sr, sd;
int fc, fr, fd;

int bfs(int c, int r, int d) {
    int t, nc, nr, nd;
    queue<position> posQueue;
    posQueue.push({c, r, d, 0});
    visit[c][r][d] = true;
    
    while (!posQueue.empty()) {
        c = posQueue.front().c;
        r = posQueue.front().r;
        d = posQueue.front().d;
        t = posQueue.front().t;
        posQueue.pop();
        if (c == fc && r == fr && d == fd) return t;
        
        // 전진
        for (int i = 1; i <= 3; i ++) {
            nc = c + dir[0][d] * i;
            nr = r + dir[1][d] * i;
            if (nc < 1 || nc > m || nr < 1 || nr > n || map[nc][nr] == 1) break;
            if (visit[nc][nr][d]) continue;
            posQueue.push({nc, nr, d, t+1});
            visit[nc][nr][d] = true;
        }
        // 회전
        for (int i = 0; i < 2; i++) {
            nd = d < 3 ? 3 + i : 1 + i;
            if (visit[c][r][nd]) continue;
            posQueue.push({c, r, nd, t+1});
            visit[c][r][nd] = true;
        }
    }
    
    return -1;
}

int main() {
    int ans;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    scanf("%d %d %d", &sc, &sr, &sd);
    scanf("%d %d %d", &fc, &fr, &fd);
    ans = bfs(sc, sr, sd);
    printf("%d", ans);
    
    return 0;
}
#endif


// 리사의 생일파티
#if 0
#include <cstdio>
#define MAXN (100)
int N;//재료종류
int M;//가진 돈
int X[MAXN];//필요양
int Y[MAXN];//주방에 있는 양
int Sm[MAXN];//작은 포장에 담긴 재료개수
int Pm[MAXN];//작은 포장 가격
int Sv[MAXN];//큰 포장에 담긴 재료개수
int Pv[MAXN];//큰 포장 가격

using namespace std;

void InputData(){
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++){
        scanf("%d %d %d %d %d %d", &X[i], &Y[i], &Sm[i], &Pm[i], &Sv[i], &Pv[i]);
    }
}

int CalCost(int idx, int need){
    int sm=Sm[idx], pm=Pm[idx], sv=Sv[idx], pv=Pv[idx];
    int e=(need+sv-1)/sv;//큰 포장으로만 구매할 경우 필요개수(올림필요)
    int minv = e * pv;//큰 포장으로만 구매할 때 가격
    for (int vcnt=0; vcnt<e; vcnt++){//큰 포장 구매 개수
        int mcnt = (need - vcnt*sv + sm-1) / sm;//작은 포장 구매 개수
        if (mcnt < 0) mcnt = 0;//큰 포장으로 충분한 경우 음수 발생할 수 있음(주의)
        int cost = pm*mcnt + pv*vcnt;
        if (minv > cost) minv = cost;
    }
    return minv;
}

int isPossible(int m){
    int sum=M;
    for (int i=0; i<N; i++){
        int need = X[i] * m - Y[i];//필요양-주방에있는양
        if (need <= 0) continue;//구매 필요없음
        sum -= CalCost(i, need);//i번 재료를 need만큼 구매할때필요한 최소금액
        if (sum < 0) return 0;//불가능
    }
    return 1;//구매가능
}

int Solve(){
    int s, e, m, sol;
    for (e=1; isPossible(e); e*=2);
    sol=s=e/2;
    while(s<=e){
        m=(s+e)/2;
        if (isPossible(m)) { sol=m; s=m+1; }
        else e=m-1;
    }
    return sol;
}

int main(){
    InputData();
    int ans = Solve();
    printf("%d\n", ans);
    return 0;
}
#endif

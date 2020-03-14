// 건물 세우기
#if 0
#include <cstdio>
#define MAX 10
using namespace std;

int n;
int prices[MAX][MAX];
int visited[MAX];

int columns[MAX];
int finalRow[MAX];
int min = 987987987;

void newRow() {
    for (int i = 0;i < n ; i++) {
        finalRow[i] = columns[i];
    }
}

void dfs(int c, int r, int sum, int cnt) {
    visited[r] = true;
    columns[c] = r;
    sum += prices[c][r];
    if (sum > min) return;
    if (cnt >= n && sum < min) {
        newRow();
        min = sum;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(c+1, i, sum, cnt +1);
            visited[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &prices[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        dfs(0, i, 0, 1);
        visited[i] = false;
    }
    
    printf("%d\n", min);
    for (int i = 0; i < n; i++) {
        printf("%d ", finalRow[i]+1);
    }
    return 0;
}

#endif

// 스도쿠
#if 0
#include <cstdio>
#include <vector>
using namespace std;

int table[9][9];
int emptyLocs[81][2];
int emptyCnt;
bool success;

bool isPossible(int c, int r, int num) {
    int sc, sr;
    sc = (c / 3) * 3;
    sr = (r / 3) * 3;
    
    for (int i = 0; i < 9; i++) {
        if (table[c][i] == num) return false;
    }
    for (int i = 0; i < 9; i ++) {
       if (table[i][r] == num) return false;
    }
    for (int i = sc; i < sc+3; i++) {
        for (int j = sr; j < sr+3; j++) {
            if (table[i][j] == num) return false;
        }
    }
    
    return true;
}

void dfs(int idx) {
    int c, r;
    if (emptyCnt <= idx) {
        success = true;
        return;
    }
    
    c = emptyLocs[idx][0];
    r = emptyLocs[idx][1];
    
    for (int i = 1; i <= 9; i++) {
        if (isPossible(c, r, i)) {
            table[c][r] = i;
            dfs(idx+1);
            if (!success) table[c][r] =0;
        }
    }
}

int main() {
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &table[i][j]);
            if (!table[i][j]) {
                emptyLocs[emptyCnt][0] = i;
                emptyLocs[emptyCnt++][1] = j;
            }
        }
    }

    dfs(0);
    for (int i = 0; i < 9; i ++) {
         for (int j = 0; j < 9; j++) {
             printf("%d ", table[i][j]);
         }
        printf("\n");
     }
    
    return 0;
}
#endif

// 해밀턴 순환회로
#if 0
#include <cstdio>
using namespace std;
#define MAX 12

int n;
int prices[MAX][MAX];
int minPrice = 987987987;
bool visit[MAX];

void dfs(int x, int sum, int cnt) {
    if (cnt == n - 1 && prices[x][0]) {
        sum += prices[x][0];
        if (sum < minPrice) minPrice = sum;
        return;
    }
    visit[x] = true;
    
    for (int i = 0; i < n; i++) {
        if (!visit[i] && prices[x][i]) {
            dfs(i, sum + prices[x][i], cnt + 1);
            visit[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &prices[i][j]);
        }
    }
    
    dfs(0, 0, 0);
    printf("%d", minPrice);
    
    return 0;
}
#endif

// 페그 솔리테어
#if 0
#include <cstdio>
#include <vector>
using namespace std;

char board[5][9];
int dir[2][4] = {{0, 0, -1, 1}, {1, -1, 0, 0}};

int moveCnt, pinCnt;
int minPin = 10;
int finalMoveCnt;

int countPin() {
    int cnt = 0;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 'o') cnt ++;
        }
    }
    
    return cnt;
}

void dfs(int cnt) {
    int c, r, nc, nr, tempmin;
    int move = 0;
    
    for (int pc = 0; pc < 5; pc ++) {
        for (int pr = 0; pr < 9; pr ++) {
            if (board[pc][pr] == 'o') {
                for (int i = 0; i < 4; i++ ){
                    c = pc + dir[0][i];
                    r = pr + dir[1][i];
                    
                    if (c < 0 || c >= 5 || r < 0 || r >= 9) continue;
                    if (board[c][r] == 'o') {
                        nc = c + dir[0][i];
                        nr = r + dir[1][i];
                        
                        if (nc < 0 || nc >= 5 || nr < 0 || nr >= 9) continue;
                        if (board[nc][nr] == '.') {
                            move = 1;
                            board[nc][nr] = 'o';
                            board[c][r] = board[pc][pr] = '.';
                            
                            dfs(cnt + 1);
                            
                            board[nc][nr] = '.';
                            board[c][r] = board[pc][pr] = 'o';
                        }
                    }
                }
            }
        }
    }
    
    if (!move) {
        tempmin = countPin();
        if (tempmin < minPin) {
            minPin = tempmin;
            finalMoveCnt = cnt;
        }
        if (tempmin == minPin){
            if (finalMoveCnt > cnt) finalMoveCnt = cnt;
        }
    }
    
}

int main() {
    int Test; char temp;
    scanf("%d", &Test);
    
    for (int t = 0; t < Test; t++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j <= 9; j++) {
                scanf("%c", &temp);
                if (j) board[i][j-1] = temp;
            }
        }
        scanf("%c", &temp);
        
        minPin = countPin();
        moveCnt = 0;
        dfs(0);
        printf("%d %d\n", minPin, finalMoveCnt);
    }
    return 0;
}
#endif


// 월드컵
#if 01
#include <cstdio>
using namespace std;

int results[6][3];
int visit[6];
bool possible;

void dfs(int ci, int cj) {
    if (ci == 6) {
        //printf("%d DONE!\n", ci);
        possible = true;
        return;
    }
    if (cj == 6) dfs(ci + 1, ci + 2);
    else {
        if (results[cj][2] && results[ci][0]) {
            // ci 승 i 패
            results[ci][0] --;
            results[cj][2] --;
            dfs(ci, cj+1);
            results[ci][0] ++;
            results[cj][2] ++;
        }
        if (results[cj][1] && results[ci][1]) {
            // 무승부
            results[ci][1] --;
            results[cj][1] --;
            dfs(ci, cj+1);
            results[ci][1] ++;
            results[cj][1] ++;
        }
        if (results[cj][0] && results[ci][2]) {
            // ci 패 i 승
            results[ci][2] --;
            results[cj][0] --;
            dfs(ci, cj+1);
            results[ci][2] ++;
            results[cj][0] ++;
        }
    }
    
}

int main() {
    int num;
    
    for (int t = 0; t < 4; t ++) {
        num = 0;
        for (int i = 0; i < 6; i ++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &results[i][j]);
                num += results[i][j];
            }
        }
        possible = false;
        if (num == 30) dfs(0, 1);
        printf(possible ? "1 ": "0 ");
    }
    
    return 0;
}
#endif

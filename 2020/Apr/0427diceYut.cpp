#include <stdio.h>

int dices[10], locs[4];
int ans;
bool visit[35];

struct POS {
    int next;
    int value;
    int blue;
};
POS gameBoard[35];
int values[] = {22, 24, 25, 30, 35, 13, 16, 19, 28, 27, 26};

void setGameBoard() {
    for (int i = 0; i <= 20; i++) {
        gameBoard[i].next = i+1;
        gameBoard[i].value = i*2;
    }
    gameBoard[5].blue = 27;
    gameBoard[10].blue = 22;
    gameBoard[15].blue = 30;
    
    // 세로
    for (int i = 22; i <= 26; i++) {
        gameBoard[i].next = i+1;
        if (i == 26) gameBoard[i].next = 20;
        gameBoard[i].value = values[i-22];
    }
    // 왼쪽
    for (int i = 27; i <= 29; i++) {
        gameBoard[i].next = i+1;
        if (i == 29) gameBoard[i].next = 24;
        gameBoard[i].value = values[i-22];
    }
    // 오른쪽
    for (int i = 30; i <= 32; i++) {
        gameBoard[i].next = i+1;
        if (i == 32) gameBoard[i].next = 24;
        gameBoard[i].value = values[i-22];
    }
}

int move(int n, int dice) {
    int tempNext = gameBoard[n].blue ? gameBoard[n].blue : gameBoard[n].next;
    for (int i = 1; i < dice; i++) {
        if (tempNext == 21) return tempNext;
        tempNext = gameBoard[tempNext].next;
    }
    return tempNext;
}

void dfs(int idx, int sum) {
    if (idx >= 10) {
        if (sum > ans) ans = sum;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int loc = locs[i];
        if (loc == 21) continue;
        int nextloc = move(loc, dices[idx]);
        if (nextloc != 21 && visit[nextloc]) continue;
        visit[loc] = false;
        visit[nextloc] = true;
        locs[i] = nextloc;
        
        dfs(idx+1, sum + gameBoard[nextloc].value);
        
        locs[i] = loc;
        visit[nextloc] = false;
        visit[loc] = true;
    }
}

void solve() {
    dfs(0, 0);
}

int main() {
    setGameBoard();
    for (int i = 0; i < 10; i++) {
        scanf("%d", &dices[i]);
    }
    solve();
    printf("%d", ans);
    
    return 0;
}


  

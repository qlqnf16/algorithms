#include <stdio.h>
#define MAX 30

int N, ans, setSize;
int cards[MAX][5];

int checkedCards[3];
int sets[5000][3];

bool setVisit[MAX];

bool isSet() {
    int setCheck[4];    // 모양, 숫자, 색, 내부
    int card1 = checkedCards[0];
    int card2 = checkedCards[1];
    int card3 = checkedCards[2];
    
    for (int i = 0; i < 4; i++) {
        if (cards[card1][i] == cards[card2][i]) {
            setCheck[i] = cards[card1][i];
        } else {
            setCheck[i] = 6 - cards[card1][i] - cards[card2][i];
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if (cards[card3][i] != setCheck[i]) return false;
    }
    return true;
}

void findAllSets(int s, int n) {
    if (n >= 3) {
        if (isSet()) {
            for (int i = 0; i < 3; i++) {
                sets[setSize][i] = checkedCards[i];
            }
            setSize++;
        }
        return;
    }

    for (int i = s; i < N; i++) {
        checkedCards[n] = i;
        findAllSets(i+1, n+1);
    }
}

bool isPossible(int n) {
    for (int i =0; i < 3; i++) {
        if (setVisit[sets[n][i]]) return false;
    }
    return true;
}

void findMaxSets(int s, int n) {
    if (n > ans) ans = n;

    for (int i = s; i < setSize; i++) {
        if (!n || isPossible(i)) {
            for (int j = 0; j < 3; j++) {
                setVisit[sets[i][j]] = true;
            }
            findMaxSets(i+1, n+1);
            for (int j = 0; j < 3; j++) {
                setVisit[sets[i][j]] = false;
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%1d", &cards[i][j]);
        }
    }
    findAllSets(0, 0);
    findMaxSets(0, 0);
    printf("%d", ans);
    return 0;
}

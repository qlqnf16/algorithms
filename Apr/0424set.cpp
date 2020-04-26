#include <stdio.h>
#define MAX 30

int N, ans, setSize;
int cards[MAX][5];

int checkedCards[3];
int sets[5000][3];

bool setVisit[MAX];

bool isSet() {
    int card1, card2, card3;
    
    for (int i = 0; i < 4; i++) {
        card1 = cards[checkedCards[0]][i];
        card2 = cards[checkedCards[1]][i];
        card3 = cards[checkedCards[2]][i];
        
        if (card1 == card2) {
            if (card3 != card1) return false;
        } else {
            if (card3 != 6 - card1 - card2) return false;
        }
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

int findMaxSets(int s, int n) {
    if (n > ans) ans = n;
    if (n >= N/3) return 1;
    if (setSize - s < ans) return 0;

    for (int i = s; i < setSize; i++) {
        if (!n || isPossible(i)) {
            for (int j = 0; j < 3; j++) {
                setVisit[sets[i][j]] = true;
            }
            if (findMaxSets(i+1, n+1)) return 1;
            for (int j = 0; j < 3; j++) {
                setVisit[sets[i][j]] = false;
            }
        }
    }
    
    return 0;
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


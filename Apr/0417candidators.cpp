
#include <cstdio>
#include <algorithm>
using namespace std;

int N;

class Candidator {
private:
    int id;
    int totalScore;
    int threes;
    int twos;
    int ones;
    
public:
    Candidator(int _id) {
        id = _id;
        totalScore = 0;
        threes = 0;
        twos = 0;
        ones = 0;
    }
    
    void addVote(int score) {
        if (score == 1) {
            ones++;
            totalScore += 1;
        }
        if (score == 2) {
            twos ++;
            totalScore += 2;
        }
        if (score == 3) {
            threes ++;
            totalScore += 3;
        }
    }
    
    void printResult() {
        printf("%d %d", id, totalScore);
    }
    
    int getTotal() {
        return totalScore;
    }
    
    bool operator < (Candidator& a) {
        if (totalScore < a.totalScore) return true;
        if (totalScore > a.totalScore) return false;
        
        if (threes < a.threes) return true;
        if (threes > a.threes) return false;
        if (twos < a.twos) return true;
        
        return false;
    }
    
    bool operator == (Candidator& a) {
        if (totalScore == a.totalScore && threes == a.threes && twos == a.twos) return true;
        return false;
    }
};

int main() {
    Candidator cand1 = Candidator(1);
    Candidator cand2 = Candidator(2);
    Candidator cand3 = Candidator(3);
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int score1, score2, score3;
        scanf("%d %d %d", &score1, &score2, &score3);
        cand1.addVote(score1);
        cand2.addVote(score2);
        cand3.addVote(score3);
    }
    
    if (cand2 < cand1 && cand3 < cand1) cand1.printResult();
    else if (cand1 < cand2 && cand3 < cand2) cand2.printResult();
    else if (cand1 < cand3 && cand2 < cand3) cand3.printResult();
    else {
        printf("0 %d", max({cand1.getTotal(), cand2.getTotal(), cand3.getTotal()}));
    }
    
    return 0;
}

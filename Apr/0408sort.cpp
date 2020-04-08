#include <cstdio>
#define MAX 100001
using namespace std;

int N;
int count[MAX];

int main(void) {
    int temp, max = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        count[temp] ++;
        if (temp > max) max = temp;
    }
    
    for (int i = 1; i <= max; i++) {
        if (!count[i]) continue;
        for (int j = 0; j < count[i]; j++) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}

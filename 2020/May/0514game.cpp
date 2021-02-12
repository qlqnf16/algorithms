#include <stdio.h>

long long X, Y;

long long solve() {
    long long s, e, m;
    long long Z = Y*100/X;
    if (Z >= 99) return -1;
    s = 1;
    e = X;
    
    while (s <= e) {
        m = (s + e) / 2;
        if ((Y+m)*100/(X+m) > Z) {
            e = m-1;
        } else {
            s = m+1;
        }
    }
    
    return s;
}

int main() {
    scanf("%lld %lld", &X, &Y);
    printf("%lld", solve());
    return 0;
}

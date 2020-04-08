#include <cstdio>
using namespace std;
int count[26];

int main(void) {
    char in;
    int max = 0;
    
    while ((in = getchar()) != EOF) {
        if (in >= 'a' && in <= 'z') {
            count[in-'a']++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) max = count[i];
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] == max) printf("%c", 'a'+i);
    }
    
    return 0;
}

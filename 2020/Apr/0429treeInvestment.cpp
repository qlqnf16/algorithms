#include <stdio.h>
#include <string.h>
#define MAXN 10

int N, M, K;
int A[MAXN+2][MAXN+2];
int map[MAXN+2][MAXN+2];
int aliveCnt, fallCnt;
int fall[MAXN+2][MAXN+2];

struct NODE {
    int age, n;
    NODE * next;
    // 구조체 생성자, 소멸자
    NODE() { age = n = 0; next = NULL; }
    NODE(int age, int n, NODE *next) {
        this->age = age;
        this->n = n;
        this->next = next;
    }
    ~NODE() { delete next; }
    // 함수
    void insert(int age, int n) {
        if ((next == NULL) || (next->age > age)) {
            next = new NODE(age, n, next);
            return;
        }
        if (next->age == age) {
            next->n += n;
            return;
        }
        next->insert(age, n);
    }
    void springSummer(int *m) {
        if (next == NULL) return;
        if (next->age * next->n > *m) {
            int rem = *m / next->age;
            NODE * bn;
            if (rem) {
                bn = next->next;
                next->next = NULL;
                aliveCnt += rem;
                *m -= next->age * rem;
                next->age++;
                if (next->age % 5 == 0) fallCnt += rem;
                *m += (next->age-1)/2 * (next->n - rem);
                next->n = rem;
            } else {
                bn = next; next = NULL;
            }
            for (NODE *p=bn; p !=NULL; p = p->next) {
                *m += (p->age / 2) * (p->n);
            }
            delete bn;
            return;
        }
        *m -= (next->age * next->n);
        next->age ++;
        if (next->age % 5 == 0) fallCnt += next->n;
        aliveCnt += next->n;
        next->springSummer(m);
    }
};

NODE head[MAXN+2][MAXN+2];
void init() {
    memset(map, 0xff, sizeof(map));
    for (int i = 1; i <= MAXN; i++) {
        for (int j = 1; j <= MAXN; j++) {
            head[i][j].next = NULL;
        }
    }
}

void inputData() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &A[i][j]);
            map[i][j] = 5;
        }
    }
    for (int i = 0; i < M; i++) {
        int c, r, age;
        scanf("%d %d %d", &c, &r, &age);
        head[c][r].insert(age, 1);
    }
}

int springSummer() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            aliveCnt = fallCnt = 0;
            head[i][j].springSummer(&map[i][j]);
            cnt += aliveCnt;
            fall[i][j] = fallCnt;
        }
    }
    return cnt;
}

int autumn() {
    int cnt = 0;
    static int dir[][8] = {{-1, -1, -1, 0, 0, 1, 1, 1}, {-1, 0, 1, -1, 1, -1, 0, 1}};
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!fall[i][j]) continue;
            for (int d = 0; d < 8; d++) {
                int nc = i + dir[0][d];
                int nr = j + dir[1][d];
                if (map[nc][nr] < 0) continue;
                head[nc][nr].insert(1, fall[i][j]);
                cnt += fall[i][j];
            }
        }
    }
    
    return cnt;
}

void winter() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] += A[i][j];
        }
    }
}

int solve() {
    int count = 0;
    for (int k = 0; k < K; k++) {
        count = springSummer();
        count += autumn();
        winter();
    }
    return count;
}

int main() {
    init();
    inputData();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}


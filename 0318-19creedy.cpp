
// 거스름돈
#if 0
#include <cstdio>


int coins[] = {500, 100, 50, 5, 1};
int pay;

int findMinIdx(int s) {
    for (int i = s; i < 5; i++) {
        if (coins[i] <= pay) return i;
    }
    return -1;
}

int main() {
    int minidx = 0, count = 0;
    
    scanf("%d", &pay);
    while (pay) {
        minidx = findMinIdx(minidx);
        count += pay / coins[minidx];
        pay %= coins[minidx];
    }

    printf("%d", count);
    
    return 0;
}
#endif

// fractional knapsack
#if 0
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 100010

struct snack {
    double cost;
    int count;
} snacks[MAX];
int n, weight;

bool compare(const snack& a, const snack& b) {
    if (a.cost < b.cost) return false;
    return true;
}

int main() {
    double costSum = 0;
    int cnt = 0;
    
    scanf("%d %d", &n, &weight);
    for (int i = 0; i < n; i++) {
        double w, c;
        scanf("%lf %lf", &w, &c);
        snacks[i].cost = c / w;
        snacks[i].count = w;
    }
    
    sort(snacks, snacks+n, compare);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < snacks[i].count; j++) {
            costSum += snacks[i].cost;
            cnt ++;
            if (cnt >= weight) break;
        }
        if (cnt >= weight) break;
    }
    
    printf("%.3lf", costSum);
    
    return 0;
}
#endif

// 동전 자판기
#if 0
#include <cstdio>
using namespace std;

int coins[] = {500, 100, 50, 10, 5, 1};
int currentCoinCounts[6];
int cost;

int main() {
    int max = 0, coinCount = 0;
    scanf("%d", &cost);
    for (int i = 0; i < 6; i++) {
        scanf("%d", &currentCoinCounts[i]);
        max += currentCoinCounts[i] * coins[i];
    }
    
    max -= cost;
    for (int i = 0; i < 6; i++) {
        while (currentCoinCounts[i] && max >= coins[i]) {
                max -= coins[i];
                currentCoinCounts[i] --;
        }
    }
    
    for (int i = 0; i < 6; i++) {
        coinCount += currentCoinCounts[i];
    }
    
    printf("%d\n", coinCount);
    for (int i = 0; i < 6; i++) {
        printf("%d ", currentCoinCounts[i]);
    }
    
    return 0;
}
#endif

// 회의실 준비
#if 0
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 100010;

struct time {
    int start;
    int end;
};

int n;
struct time meetings[MAX];
struct time rooms[MAX];


bool compare(const struct time& a, const struct time& b) {
    if (a.start < b.start) return true;
    if (a.start == b.start) {
        if (a.end < b.end) return true;
        return false;
    }
    return false;
}

int main() {
    int idx = 0, changed;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }
    
    sort(meetings, meetings+n, compare);
    
    for (int i = 0; i < n; i++) {
        changed = 0;
        for (int j = 0; j < idx; j++) {
            if(rooms[j].end <= meetings[i].start) {
                rooms[j].end = meetings[i].end;
                changed = 1;
                break;
            }
        }
        
        if (!changed) {
            rooms[idx].start = meetings[i].start;
            rooms[idx++].end = meetings[i].end;
        }
    }
    
    printf("%d", idx);
    
    return 0;
}
#endif

// 기울기가 가장 큰 두 점 찾기
#if 0
#include <cstdio>
#include <algorithm>
#define MAX 100010
using namespace std;

struct st {
    double x;
    double y;
} points[MAX];
int n;
double maxSlope;

bool compare(const st& a, const st& b) {
    if (a.x < b.x) return true;
    return false;
}

double absNum(double num) {
    if (num < 0) return num * -1;
    return num;
}

int main() {
    double slope;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    sort(points, points+n, compare);
    
    for (int i = 0; i < n-1; i++) {
        slope = absNum(points[i+1].y - points[i].y) / absNum(points[i+1].x - points[i].x);
        if (slope > maxSlope) maxSlope = slope;
    }
    printf("%.3lf", maxSlope);
    
    return 0;
}
#endif

// 미팅 참석
#if 0
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 100010;

struct time {
    int start;
    int end;
};

int n;
struct time meetings[MAX];
struct time rooms[MAX];
int maxMeet;

bool compare(const struct time& a, const struct time& b) {
    if (a.end < b.end) return true;
    if (a.end == b.end) {
        if (a.start < b.start) return true;
        return false;
    }
    return false;
}

int main() {
    int idx = 0, changed;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }
    
    sort(meetings, meetings+n, compare);
    
    for (int i = 0; i < n; i++) {
        changed = 0;
        for (int j = 0; j < idx; j++) {
            if(rooms[j].end <= meetings[i].start) {
                rooms[j].end = meetings[i].end;
                rooms[j].start ++;
                if (rooms[j].start > maxMeet) maxMeet = rooms[j].start;
                changed = 1;
                break;
            }
        }
        
        if (!changed) {
            rooms[idx].start = 1;
            rooms[idx++].end = meetings[i].end;
        }
    }
    
    printf("%d", maxMeet);
    
    return 0;
}
#endif

// 회의실 BIG
#if 0
#include <cstdio>
#include <algorithm>
#define MAX 1000010
using namespace std;

int n;
int s = 2000000, e, myMax;
int nums[MAX];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        nums[a]++;
        nums[b]--;
        
        if (a < s) s = a;
        if (b > e) e = b;
    }
    
    for (int i = s; i < e; i++) {
        nums[i+1] += nums[i];
        if (nums[i+1] > myMax) myMax = nums[i+1];
    }
    
    printf("%d", myMax);
    return 0;
}
#endif

// 냉장고
#if 0
#include <cstdio>
#include <algorithm>
#define MAX 110
using namespace std;

struct st {
    int from;
    int to;
} temperature[MAX];
int n;
int fridges[MAX];

bool compare(const st& a, const st& b) {
    if (a.from < b.from) return true;
    if (a.from == b.from) {
        if (a.to < b.to) return true;
        return false;
    }
    return false;
}

int main() {
    int fi  = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        temperature[i].from = from;
        temperature[i].to = to;
    }
    sort(temperature, temperature+n, compare);
    fridges[fi] = temperature[0].to;
    for (int i = 1; i < n; i++) {
        if (temperature[i].from <= fridges[fi]) {
            if (temperature[i].to < fridges[fi]) fridges[fi] = temperature[i].to;
        }
        else {
            fridges[++fi] = temperature[i].to;
        }
    }
    
    printf("%d", fi);
    return 0;
}

#endif

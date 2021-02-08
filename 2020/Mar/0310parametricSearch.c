//
//  0310parametricSearch.c
//  Algorithm
//
//  Created by Jeong Min Lee on 2020/03/10.
//  Copyright © 2020 Jeong Min Lee. All rights reserved.
//

// 과제 - 예산
#if 0
#include <stdio.h>
#define MAX 10001

int n;
int budgets[MAX];
int total;

int countTotal(int max) {
    int sum = 0;
    
    for (int i = 0; i < n; i++){
        if (budgets[i] <= max) sum += budgets[i];
        else sum += max;
    }
    
    return sum;
}

int binarySearch(int s, int e) {
    int mid, start = s, end = e, tempTotal;
    if (countTotal(e) < total) return e;
    
    while (start + 1 < end) {
        mid = (start+end) / 2;
        tempTotal = countTotal(mid);
        if (tempTotal < total) start = mid;
        else if (tempTotal > total) end = mid;
        else return mid;
    }
    
    return start;
}

int main(void) {
    int start, end, max = 0, top;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &budgets[i]);
        if (budgets[i] > max) max = budgets[i];
    }
    scanf("%d", &total);
    
    start = total / n;
    end = max;
    top = binarySearch(start, end);
    
    printf("%d", top);
    
    return 0;
}
#endif

// 나무 자르기
#if 0
#include <stdio.h>
#define MAX 1000001

int n, goal;
int trees[MAX];

long long countTrees(int height) {
    long long sum = 0;
    
    for (int i = 0; i < n; i ++) {
        if (trees[i] > height) sum += trees[i] - height;
    }
    
    return sum;
}

int binarySearch(int s, int e) {
    int mid, start = s, end = e;
    long long sum;
    
    while (start + 1 < end) {
        mid = (start + end) / 2;
        sum = countTrees(mid);
        if (sum < goal) end = mid;
        else start = mid;
    }
    
    return start;
}

int main(void) {
    int max = 0, height;
    
    scanf("%d %d", &n, &goal);
    for (int i = 0; i < n; i++) {
        scanf("%d", &trees[i]);
        if (trees[i] > max) max = trees[i];
    }
    
    height = binarySearch(0, max);
    printf("%d", height);
    
    return 0;
}
#endif

// NN단표
#if 0
#include <stdio.h>

int n;
long long k;

int countLessNumbers(long long base) {
    long long count = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i > base) break;
        
        if (base/i > n) count += n;
        else count += base/i;
    }
    
    if (count >= k) return 1;
    else return 0;
}

int main(void) {
    long long start, end, mid;
    
    scanf("%d %lld", &n, &k);
    start = 1; end = k*k;
    
    if (k == 1) {
        printf("1");
        return 0;
    }
    
    while (start + 1 < end) {
        mid = (start + end) / 2;
        if (countLessNumbers(mid)) end = mid;
        else start = mid;
    }
    
    printf("%lld", end);
    
    return 0;
}
#endif

// 중복 없는 구간
#if 0
#include <stdio.h>
#define MAX 100001

int nums[MAX];
int n;
int visitCheck[MAX];

int main(void) {
    //int start = 0, end;
    int p = 0, q = 0, max = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    while (q <= p && p < n) {
        if (!visitCheck[nums[p]]) {
            if (p-q+1 > max) max = p-q+1;
            visitCheck[nums[p++]] ++;
        } else {
            visitCheck[nums[q++]] --;
        }
    }
    
    printf("%d", max);
    
    return 0;
}
#endif

// 구간의 합집합
#if 0
#include <stdio.h>
#define MAX 10001

typedef struct {
    long long from;
    long long to;
} range;

int n;
long long idx;
range ranges[MAX];

int isCountGreaterThanIdx(long long mid) {
    long long count = 0;
    for (int i = 0; i < n; i ++) {
        if (ranges[i].from <= mid && ranges[i].to >= mid) count += mid - ranges[i].from;
        else if (ranges[i].to < mid) count += ranges[i].to - ranges[i].from + 1;
    }
    
    if (count > idx) return 1;
    else return 0;
}

int main(void) {
    long long start = 1000000001, end = 0, mid;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &ranges[i].from, &ranges[i].to);
       
        if (ranges[i].from < start) start = ranges[i].from;
        if (ranges[i].to > end) end  = ranges[i].to;
    }
    scanf("%lld", &idx);
    end ++;
    
    while (start + 1 < end) {
        mid = (start + end) / 2;
        if (isCountGreaterThanIdx(mid)) end = mid;
        else start = mid;
    }
    
    printf("%lld", start);
    
    return 0;
}
#endif

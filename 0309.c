// 숫자박스
#if 0
#include <stdio.h>

#define MAX 300001
#define CASEMAX 500001

int nums[MAX];
int questions[CASEMAX];
int n, q;

void binarySearch(int target);
void quick_sort(int* data, int start, int end);

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &nums[i]);
    }
    
    scanf("%d", &q);
    for (int i = 0; i < q; i ++) {
        scanf("%d", &questions[i]);
    }
    quick_sort(nums, 0, n-1);
    for (int i = 0; i < q; i++) {
        binarySearch(questions[i]);
    }
    
    return 0;
}


void binarySearch(int target) {
    int s = 0, e = n-1, m = (s+e)/2;
    
    while (1) {
        if (nums[m] == target) {
            printf("1\n");
            return;
        }
        if (s>e) {
            printf("0\n");
            return;
        }
        
        if (nums[m] > target) {
            e = m-1;
            m = (s+e)/2;
        } else if (nums[m] < target) {
            s = m+1;
            m = (s+e)/2;
        }
    }
}

void quick_sort(int *data, int start, int end){
    if(start >= end) return;
    int pivot = start;
    int i = pivot + 1; // 왼쪽 출발 지점
    int j = end; // 오른쪽 출발 지점
    int temp;
    
    while(i <= j){
        // 포인터가 엇갈릴때까지 반복
        while(i <= end && data[i] <= data[pivot]){ i++; }
        while(j > start && data[j] >= data[pivot]){ j--; }
        if(i > j){
            // 엇갈림
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        } else {
            // i번째와 j번째를 스왑
            temp = data[i];
            data[i] = data[j];
            data[j] = temp; }
    }
    
    // 분할 계산
    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end); }

#endif

// 2차식 정답 추측
#if 0
#include <stdio.h>
#include <math.h>

long long a;

int main(void) {
    long long mid, start, end;
    scanf("%lld", &a);
    
    start = 0;
    end = (long long)sqrt((double)a);

    while(start + 1 < end){
        mid = (start+end) / 2;
        if(mid * (mid+1) == a) {
            start = mid;
            break;
        }
        else if (mid * (mid+1) < a) start = mid;
        else end = mid;
    }
    
    printf("%lld", start);
    return 0;
}

#endif


// 숫자 개수 세기
#if 0
#include <stdio.h>
#define MAX 100001

long long nums[MAX];
long long questions[MAX];
int n, q;

void quick_sort(long long *data, int start, int end);

int binarySearch(long long target) {
    int s = 0, e = n-1, m = (s+e)/2;
    
    while (1) {
        if (nums[m] == target) return m;
        if (s>e) return -1;
        
        if (nums[m] > target) {
            e = m-1;
            m = (s+e)/2;
        } else if (nums[m] < target) {
            s = m+1;
            m = (s+e)/2;
        }
    }
}

int countNum(int start) {
    long long target = nums[start];
    int left = start-1, right = start+1, count = 0;
    
    while (left >= 0 && nums[left] == target) {
        left --;
        count ++;
    }
    while (right < n && nums[right] == target) {
        right++;
        count++;
    }
    
    return count;
}

int main(void) {
    int idx, count;
    
    scanf("%d %d", &n, &q);
    for (int i = 0 ;i < n ;i ++) {
        scanf("%lld", &nums[i]);
    }
    for (int i = 0; i < q;i  ++) {
        scanf("%lld", &questions[i]);
    }
    
    quick_sort(nums, 0, n-1);
    for (int i = 0; i < q; i++) {
        idx = binarySearch(questions[i]);
        if (idx == -1) {
            printf("0\n");
        } else {
            count = countNum(idx);
            printf("%d\n", count);
        }
    }
    
    return 0;
}

void quick_sort(long long *data, int start, int end){
    if(start >= end) return;
    int pivot = start;
    int i = pivot + 1; // 왼쪽 출발 지점
    int j = end; // 오른쪽 출발 지점
    long long temp;

    while(i <= j){
        // 포인터가 엇갈릴때까지 반복
        while(i <= end && data[i] <= data[pivot]){ i++; }
        while(j > start && data[j] >= data[pivot]){ j--; }
        if(i > j){
            // 엇갈림
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        } else {
            // i번째와 j번째를 스왑
            temp = data[i];
            data[i] = data[j];
            data[j] = temp; }
    }
    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end);
}

#endif

// 두 용액
#if 0
#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int nums[MAX];
int n;
int min = 2000000000;
int liq1, liq2;

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int trySum(int index) {
    int start = index+1;
    int end = n-1;
    int mid, sum;
    
    while (start <= end) {
        mid = (start + end) / 2;
        sum = nums[index] + nums[mid];
        
        if (sum == 0) {
            liq1 = index;
            liq2 = mid;
            return 0;
        } else if (sum < 0) {
            start = mid+1;
            sum *= -1;
        } else {
            end = mid-1;
        }
        
        if (sum < min) {
            liq1 = index;
            liq2 = mid;
            min = sum;
        }
    }
    
    return 1;
}

int main(void) {
    int sum;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    qsort(nums, n, sizeof(int), compare);

    for (int i = 0; i < n-1; i++) {
        sum = trySum(i);
        if (!sum) break;
    }

    printf("%d %d\n", nums[liq1], nums[liq2]);
    
    return 0;
}

#endif


#if 01
#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

struct st {
    long long x;
    long long y;
} animals[MAX];
int n, m; long long l;
long long locs[MAX];
int count = 0;

void catchAnimals(int aidx);
int compareLocs(const void *a, const void *b);

int main(void)
{
    scanf("%d %d %lld", &n, &m, &l);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &locs[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld %lld", &animals[i].x, &animals[i].y);
    }
    qsort(locs, n, sizeof(long long), compareLocs);
    
    for (int i = 0; i < m; i++) {
        catchAnimals(i);
    }
    
    printf("%d", count);
    
    return 0;
}

void catchAnimals(int id) {
    int start = 0, end = n-1, mid;
    long long x = animals[id].x;
    long long y = animals[id].y;
    long long distance;
    
    while (start <= end) {
        mid = (start + end) / 2;
        
        if (locs[mid] < x) {
            distance = x - locs[mid] + y;
            if (distance <= l) {
                count ++;
                return;
            } else {
                start = mid +1;
            }
        } else {
            distance = locs[mid] - x + y;
            if (distance <= l) {
                count ++;
                return;
            } else {
                end = mid -1;
            }
        }
    }
}

int compareLocs(const void *a, const void *b) {
     long long num1 = *(long long *)a;
     long long num2 = *(long long *)b;

     if (num1 < num2) return -1;
     if (num1 > num2) return 1;
     return 0;
}

#endif

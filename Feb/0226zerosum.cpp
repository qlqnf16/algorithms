#include <algorithm>
#include <cstdio>
#define MAX 4000
using namespace std;

int N;
int nums[4][MAX];
int sumOfAB[MAX * MAX];

void input();

long long solve() {
  long long res = 0;

  for (int i = 0, idx = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sumOfAB[idx++] = nums[0][i] + nums[1][j];
    }
  }
  int cnt = N * N;
  sort(sumOfAB, sumOfAB + cnt);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int sumOfCD = (nums[2][i] + nums[3][j]) * -1;
      long long zeros = upper_bound(sumOfAB, sumOfAB + cnt, sumOfCD) -
                        lower_bound(sumOfAB, sumOfAB + cnt, sumOfCD);
      res += zeros;
    }
  }
  return res;
}

int main() {
  input();
  printf("%lld", solve());
  return 0;
}

void input() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d %d", &nums[0][i], &nums[1][i], &nums[2][i], &nums[3][i]);
  }
}
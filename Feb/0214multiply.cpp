#include <cstdio>
using namespace std;

int A, B, C;

long long dc(int a, int b) {
  if (b == 1)
    return a % C;

  long long val = dc(a, b / 2);
  if (b % 2 == 0) {
    return val * val % C;
  } else {
    return val * val * a % C;
  }
}

int main() {
  scanf("%d %d %d", &A, &B, &C);
  long long ans = dc(A, B);
  printf("%lld", ans);
  return 0;
}
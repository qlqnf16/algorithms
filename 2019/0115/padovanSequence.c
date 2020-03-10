#include <stdio.h>

#define MAX 101
long long dp[MAX] = {0};

int main(void)
{
  int n, i, t, c;
  scanf("%d", &t);

  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;

  for (i = 4; i <= 100; i++)
  {
    dp[i] = dp[i - 2] + dp[i - 3];
  }

  for (c = 0; c < t; c++)
  {
    scanf("%d", &n);
    printf("%lld\n", dp[n]);
  }

  return 0;
}
#include <stdio.h>

#define MAX 1000001
long long dp[MAX] = {0};

int main(void)
{
  int n, i;
  scanf("%d", &n);

  dp[1] = 1;
  dp[2] = 2;

  for (i = 3; i <= n; i++)
  {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
  }

  printf("%lld", dp[n]);

  return 0;
}
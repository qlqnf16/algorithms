#include <stdio.h>

int n, m;
int visit[9] = {0}, combi[9];

int addNumToArr(int index)
{
  if (index == m)
  {
    for (int i = 0; i < m; i++)
    {
      printf("%d ", combi[i]);
    }
    printf("\n");
  }

  for (int i = 0; i < n; i++)
  {
    if (!visit[i])
    {
      combi[index] = i + 1;
      visit[i] = 1;
      addNumToArr(index + 1);
      visit[i] = 0;
    }
  }
}

int main(void)
{
  scanf("%d %d", &n, &m);
  addNumToArr(0);

  return 0;
}
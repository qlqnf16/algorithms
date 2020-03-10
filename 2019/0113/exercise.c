#include <stdio.h>

int main(void)
{
  int T;
  int lower, upper, exercise, result;
  scanf("%d", &T);

  for (int t = 0; t < T; t++)
  {
    scanf("%d %d %d", &lower, &upper, &exercise);
    if (exercise > upper)
      result = -1;
    else if (exercise < lower)
      result = lower - exercise;
    else
      result = 0;

    printf("#%d %d\n", t + 1, result);
  }

  return 0;
}
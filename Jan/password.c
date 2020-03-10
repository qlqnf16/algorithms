#include <stdio.h>
#include <math.h>

int passwords[30] = {0};
char numbers[30];

int toDecimal(int i)
{
  int sum = 0, j;

  for (j = 0; j < 3; j++)
  {
    if (numbers[i + j] >= 'A' && numbers[i + j] <= 'F')
      sum += (numbers[i + j] - ('A' - 10)) * pow(16, 2 - j);
    else
      sum += (numbers[i + j] - '0') * pow(16, 2 - j);
  }

  if (sum <= 0)
    printf("%c %c %c = %d\n", numbers[i], numbers[i + 1], numbers[i + 2], sum);
  return sum;
}

int getNums(int size)
{
  int i, temp, rank = 1;
  for (i = 0; i < size - 2; i++)
  {
    temp = toDecimal(i);
    passwords[i] = temp;
  }
}

void sort(int n)
{
  int i, j, key;
  for (i = 1; i < n; i++)
  {
    key = passwords[i];
    for (j = i - 1; j >= 0 && passwords[j] > key; j--)
    {
      passwords[j + 1] = passwords[j]; // 레코드의 오른쪽으로 이동
    }

    passwords[j + 1] = key;
  }
}

int main(void)
{
  int test, t, size, target;
  scanf("%d", &test);
  for (t = 1; t <= test; t++)
  {
    scanf("%d %d\n", &size, &target);

    int i;
    for (i = 0; i < size; i++)
    {
      scanf("%c", &numbers[i]);
    }

    getNums(size);
    sort(size);

    for (i = 0; i < size; i++)
    {
      printf("%d ", passwords[i]);
    }
    printf("\n");

    printf("#%d %d\n", t, passwords[target]);
  }
  return 0;
}
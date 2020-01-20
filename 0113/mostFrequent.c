#include <stdio.h>
  int main(void)
{
    int testCase;
    int testNum;
     
  int tempIndex;
  int mostFrequent;
  int max;
   
  scanf("%d", &testCase);
   
  for (int t = 0; t < testCase; t++)
  {
        scanf("%d", &testNum);
     
    int frequentCheck[101] = {0};
        max = 0;
     
    for (int i = 0; i < 1000; i++)
    {
            scanf("%d", &tempIndex);
            frequentCheck[tempIndex]++;
            if (frequentCheck[tempIndex] > max)
        max = frequentCheck[tempIndex];
          
    }
     
    for (int i = 0; i < 101; i++)
    {
            if (frequentCheck[i] == max) mostFrequent = i;
          
    }
     
    printf("#%d %d\n", testNum, mostFrequent);
      
  }
      return 0;
}
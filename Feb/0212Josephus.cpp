#include <cstdio>
#include <queue>
#define MAX 1010
using namespace std;

int N, K;
queue<int> nums;
int deleted[MAX];

int main()
{
  scanf("%d %d", &N, &K);
  int topIdx = K - 1;
  for (int i = 1; i <= N; i++)
  {
    nums.push(i);
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < K - 1; j++)
    {
      nums.push(nums.front());
      nums.pop();
    }
    deleted[i] = nums.front();
    nums.pop();
  }

  printf("<");
  for (int i = 0; i < N - 1; i++)
  {
    printf("%d, ", deleted[i]);
  }
  printf("%d>", deleted[N - 1]);

  return 0;
}
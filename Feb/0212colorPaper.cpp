#include <cstdio>
#define MAX 128

using namespace std;

int N;
int colors[2];
int paper[MAX][MAX];

int checkPaper(int sr, int sc, int size)
{
  int color = paper[sr][sc];
  for (int i = sr; i < sr + size; i++)
  {
    for (int j = sc; j < sc + size; j++)
    {
      if (color != paper[i][j])
        return -1;
    }
  }
  return color;
}

void cutPaper(int sr, int sc, int size)
{
  int color = checkPaper(sr, sc, size);
  if (color != -1 || size == 1)
  {
    colors[color]++;
    return;
  }

  // 4등분
  size /= 2;
  cutPaper(sr, sc, size);
  cutPaper(sr + size, sc, size);
  cutPaper(sr, sc + size, size);
  cutPaper(sr + size, sc + size, size);
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      scanf("%d ", &paper[i][j]);
    }
  }

  cutPaper(0, 0, N);
  printf("%d\n%d", colors[0], colors[1]);

  return 0;
}
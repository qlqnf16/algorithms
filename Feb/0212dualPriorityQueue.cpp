#include <cstdio>
#include <set>

using namespace std;

int T, N;
multiset<int> s;

int main()
{
  scanf("%d", &T);
  for (int t = 0; t < T; t++)
  {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
      char oper[2];
      int val;
      scanf("%s %d", oper, &val);

      if (oper[0] == 'I')
      {
        s.insert(val);
      }
      else
      {
        if (s.empty())
          continue;
        if (val == -1)
        {
          s.erase(s.begin());
        }
        else
        {
          s.erase(--s.end());
        }
      }
    }
    if (s.empty())
      printf("EMPTY\n");
    else
      printf("%d %d\n", *(--s.end()), *s.begin());
    s.clear();
  }

  return 0;
}
#include <cstdio>
#include <map>
#include <string>
#define MAX 100000 + 10

using namespace std;

int main()
{
  int N, M;
  string byIndex[MAX];
  map<string, int> byName;

  scanf("%d %d", &N, &M);

  for (int i = 1; i <= N; i++)
  {
    char input[50];
    scanf("%s", input);
    string s = input;
    byIndex[i] = s;
    byName.insert(make_pair(s, i));
  }

  for (int i = 0; i < M; i++)
  {
    char input[50];
    scanf("%s", input);
    if (input[0] >= 'A')
    {
      printf("%d\n", byName.find(input)->second);
    }
    else
    {
      int idx = atoi(input);
      printf("%s\n", byIndex[idx].c_str());
    }
  }

  return 0;
}
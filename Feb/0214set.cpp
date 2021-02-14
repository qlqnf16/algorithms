#include <cstdio>
#include <string.h>
using namespace std;

unsigned int bit = 0;

int main() {
  int N;

  char oper[7];
  int val;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s", oper);
    if (!strcmp(oper, "add")) {
      scanf("%d", &val);
      bit |= (1 << val);
    } else if (!strcmp(oper, "remove")) {
      scanf("%d", &val);
      bit &= ~(1 << val);
    } else if (!strcmp(oper, "check")) {
      scanf("%d", &val);
      if ((bit & (1 << val)) == 0)
        printf("0\n");
      else
        printf("1\n");
    } else if (!strcmp(oper, "toggle")) {
      scanf("%d", &val);
      bit ^= (1 << val);
    } else if (!strcmp(oper, "all")) {
      bit = (1 << 21) - 1;
    } else if (!strcmp(oper, "empty")) {
      bit = 0;
    }
  }

  return 0;
}
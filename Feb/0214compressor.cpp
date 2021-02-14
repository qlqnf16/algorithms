#include <algorithm>
#include <cstdio>
#define MAX 1000000 + 10
using namespace std;

int N;
struct st {
  int val;
  int idx;
  int ord;
};
st locs[MAX];

void input();

bool compByVal(st a, st b) { return a.val < b.val; }

bool compByIdx(st a, st b) { return a.idx < b.idx; }

void solve() {
  int ord = 0;
  sort(locs, locs + N, compByVal);
  locs[0].ord = ord;
  for (int i = 1; i < N; i++) {
    if (locs[i].val > locs[i - 1].val)
      ord++;
    locs[i].ord = ord;
  }
  sort(locs, locs + N, compByIdx);
  for (int i = 0; i < N; i++) {
    printf("%d ", locs[i].ord);
  }
}

int main() {
  input();
  solve();
  return 0;
}

void input() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int input;
    scanf("%d", &input);
    locs[i].val = input;
    locs[i].idx = i;
  }
}

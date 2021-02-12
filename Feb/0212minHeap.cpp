#include <cstdio>
#define MAX 100000 + 10
using namespace std;

int heap[MAX];
int heapCnt;

void swap(int idx1, int idx2)
{
  int temp = heap[idx1];
  heap[idx1] = heap[idx2];
  heap[idx2] = temp;
}

void push(int val)
{
  heapCnt++;
  heap[heapCnt] = val;

  int current = heapCnt;
  while (true)
  {
    int parent = current / 2;
    if (parent == 0 || heap[parent] < heap[current])
      break;
    swap(current, parent);
    current = parent;
  }
}

int pop()
{
  if (!heapCnt)
    return 0;
  int result = heap[1];
  heap[1] = heap[heapCnt--];

  int current = 1;
  while (true)
  {
    int child = current * 2;
    int right = current * 2 + 1;
    if (child > heapCnt)
      break;

    if (heap[child + 1] < heap[child])
      child++;
    if (heap[current] < heap[child])
      break;
    swap(current, child);
    current = child;
  }

  return result;
}

int main()
{
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    int input;
    scanf("%d", &input);
    if (input == 0)
    {
      printf("%d\n", pop());
    }
    else
    {
      push(input);
    }
  }

  return 0;
}
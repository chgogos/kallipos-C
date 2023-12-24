#include <limits.h>
#include <stdio.h>

int main(void) {
  printf("%d \n", INT_MAX);
  int N = INT_MAX;
  int a[N];

  for (int i = 0; i < N; i++)
    a[i] = 0;
}

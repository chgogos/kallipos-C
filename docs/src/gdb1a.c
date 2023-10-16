#include <stdio.h>
#include <stdlib.h>

int fun(int a[], int N) {
  int sum;
  for (int i = 0; i < N; i++) {
    sum += a[i];
  }
  return sum;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <number>", argv[0]);
    return -1;
  }
  int N = atoi(argv[1]);
  int a[N];
  for (int i = 0; i < N; i++) {
    a[i] = i;
  }

  int r1 = fun(a, N);
  int r2 = fun(a, N);
  printf("r1 = %d, r2=%d\n", r1, r2);
  return 0;
}

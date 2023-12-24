#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int *x = NULL;
  printf("Input the dimension of the array: ");
  scanf("%d", &n);
  x = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    x[i] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", x[i]);
  }
  free(x);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  char *st;
  printf("Input the number of characters for a string: ");
  scanf("%d", &n);
  st = malloc((n + 1) * sizeof(char));
  for (int i = 0; i < n; i++) {
    st[i] = 'A';
  }
  st[n] = '\0';
  printf("Result: %s\n", st);
  free(st);
  return 0;
}

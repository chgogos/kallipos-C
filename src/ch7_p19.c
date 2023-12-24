#include <stdio.h>

void modify_table(int *x, int size) {
  int pos = 0;
  while (pos != size) {
    if (pos % 2 == 0) {
      *x++ = 100;
    } else {
      *x++ = 200;
    }
    pos++;
  }
}

int main(void) {
  int t[] = {10, 20, 30, 40, 50};
  modify_table(t, 5);
  for (int i = 0; i < 5; i++) {
    printf("%d ", t[i]);
  }
  printf("\n");
  return 0;
}

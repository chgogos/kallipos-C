#include <stdio.h>

void modify_table(int *x, int size) {
  for (int i = 0; i < size; i++) {
    if (i % 2 == 0) {
      *(x + i) = 100;
    } else {
      *(x + i) = 200;
    }
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

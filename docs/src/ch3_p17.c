#include <stdio.h>

int main(void) {
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k < 10; k++) {
        printf("i=%d, j=%d, k=%d\n", i, j, k);
        if (i == 0 && j == 1 && k == 2)
          goto finish;
      }
finish:
  printf("Exit from the nested loops!\n");
  return 0;
}

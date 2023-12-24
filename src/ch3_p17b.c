#include <stdbool.h>
#include <stdio.h>

int main(void) {
  bool flag = true;
  for (int i = 0; i < 10 && flag; i++)
    for (int j = 0; j < 10 && flag; j++)
      for (int k = 0; k < 5 && flag; k++) {
        printf("i=%d, j=%d, k=%d\n", i, j, k);
        if (i == 0 && j == 1 && k == 2)
          flag = false;
      }
  if (!flag) {
    printf("Exit from the nested loops!\n");
  }
  return 0;
}

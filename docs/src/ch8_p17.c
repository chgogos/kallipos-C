#include <stdio.h>
#include <string.h>

int main(void) {
  char info[200];
  int x[5] = {10, 20, 30, 40, 50};
  strcpy(info, "");
  for (int i = 0; i < 5; i++) {
    sprintf(info, "%sx[%d]=%d\n", info, i, x[i]);
  }
  printf("%s\n", info);
  return 0;
}

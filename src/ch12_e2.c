#include <stdio.h>
#define FOREVER for (;;)

int main(void) {
  int i = 0;
  FOREVER {
    printf("Loop!\n");
    i++;
    if (i == 100)
      break;
  }
}
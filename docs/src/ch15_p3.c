#include <assert.h>
#include <stdio.h>

int main(void) {
  int d;
  printf("Input a month day for January: ");
  scanf("%d", &d);
  assert((d >= 1 && d <= 31) && "month day should be from 1 to 31");
  printf("You entered day %d\n", d);
  return 0;
}

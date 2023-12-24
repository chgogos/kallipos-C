#include <stdio.h>

int main(void) {
  int x[] = {10, 20, 200, 300, 400};
  int start_pos = 3;
  int *sub_x = &x[start_pos];
  for (int i = start_pos; i < 5; i++) {
    printf("Element at index %d of the subarray has value %d \n", i - start_pos,
           sub_x[i - start_pos]);
  }
  return 0;
}

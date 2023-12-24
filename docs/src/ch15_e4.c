#include <stdio.h>

int main(void) {
  int arr[3] = {10, 20, 30};
  void *ptr = arr;
  printf("The value that the pointer points to: %d\n", *((int *)ptr));

  ptr = ptr + 1;

  printf("The value that the pointer (after increment by 1) points to: %d\n",
         *((int *)ptr));

  return 0;
}

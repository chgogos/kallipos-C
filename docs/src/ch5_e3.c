#include <stdio.h>

int fibonacci(int n) {
  if (n <= 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    int prev = 0;
    int current = 1;
    int fib;

    for (int i = 2; i <= n; i++) {
      fib = prev + current;
      prev = current;
      current = fib;
    }
    return fib;
  }
}

int main(void) {
  int fib_array[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int index = i * 5 + j + 1;
      fib_array[i][j] = fibonacci(index);
    }
  }
  printf("5 x 5 Array filled with the first 25 Fibonacci numbers:\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%5d ", fib_array[i][j]);
    }
    printf("\n");
  }
  return 0;
}

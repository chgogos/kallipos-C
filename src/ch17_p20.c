#include <stdio.h>
#include <time.h>

int main(void) {
  clock_t start_time, end_time;
  double elapsed_time;

  start_time = clock();
  long long sum = 0;
  for (int i = 1; i <= 100000000; i++) {
    sum += i;
  }
  end_time = clock();

  elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("CLOCKS_PER_SEC=%lu, start=%lu, end=%lu\n", CLOCKS_PER_SEC, start_time,
         end_time);
  printf("Result=%lld\n", sum);
  printf("Elapsed time=%.6f seconds\n", elapsed_time);
  return 0;
}

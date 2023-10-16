#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(void) {
  for (int i = 0; i < 5; i++) {
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    srand(current_time.tv_sec * current_time.tv_usec);
    for (int j = 0; j < 10; j++) {
      double r = (double)rand() / (double)RAND_MAX;
      printf("%.4lf ", r);
    }
    printf("\n");
  }
  return 0;
}

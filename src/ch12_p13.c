#include <omp.h>
#include <stdio.h>

int main(void) {
#pragma omp parallel for num_threads(2)
  for (int i = 0; i < 6; i++) {
    printf("i = %d, thread %d\n", i, omp_get_thread_num());
  }
}

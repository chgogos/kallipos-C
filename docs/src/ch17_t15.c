#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(42); // seed=42 για επαναληψιμότητα αποτελεσμάτων
  for (int i = 0; i < 10; i++) {
    int r = rand() % 10 + 1;
    printf("%2d ", r);
  }
  printf("\n");
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    int r = rand() % 10 + 1;
    printf("%2d ", r);
  }
  printf("\n");
  return 0;
}

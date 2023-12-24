#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(42); // για επαναληψιμότητα αποτελεσμάτων χρησιμοποιείται ένα seed,
             // εδώ η τιμή 42
  for (int i = 0; i < 10; i++) {
    int r = rand() % 10 + 1;
    printf("%2d ", r);
  }
  printf("\n");
  srand(time(NULL)); // το seed αλλάζει σε κάθε εκτέλεση του προγράμματος
  for (int i = 0; i < 10; i++) {
    int r = rand() % 10 + 1;
    printf("%2d ", r);
  }
  printf("\n");
  return 0;
}

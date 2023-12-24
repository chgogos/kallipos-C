#include <stdio.h>

// λανθασμένη υλοποίηση
void swap(int *a, int *b) {
  if (a != b) { // αποφυγή undefined behavior όταν δείχνουν στην ίδια διεύθυνση
    *a = *a ^ *b;
    *a = *a ^ *b;
    *b = *a ^ *b;
  }
}

int main(void) {
  int x = 5, y = 10;
  printf("BEFORE: x = %d, y = %d\n", x, y);
  swap(&x, &y);
  printf("AFTER: x = %d, y = %d\n", x, y);
}

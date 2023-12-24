#include <stdio.h>

/*
 * Function: scale_smallest_by_factor
 * ----------------------------------------------------------------------------
 *   Επιστρέφει τη μικρότερη τιμή από τις δύο πρώτες τιμές εισόδου
 *   πολλαπλασιασμένη με την τρίτη τιμή εισόδου
 *
 *   r1: ο πρώτος πραγματικός αριθμός
 *   r2: ο δεύτερος πραγματικός αριθμός
 *   f: ο συντελεστής πολλαπλασιασμού
 *
 *   returns: η μικρότερη τιμή από τα r1 και r2 πολλαπλασιασμένη με το f
 */
double scale_smallest_by_factor(double r1, double r2, double f) {
  double min = r1;
  if (r2 < min) {
    min = r2;
  }
  return f * min;
}

int main(void) {
  double r = scale_smallest_by_factor(5.0, 4.0, 1.5);
  printf("Result %.2f\n", r);
  return 0;
}

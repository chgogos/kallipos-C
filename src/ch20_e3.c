#include <math.h>

double nth_root(double x, int n) {
  if (x < 0 && n % 2 == 0) {
    // Δεν υπάρχει πραγματική ρίζα για αρνητικό x όταν ο n είναι άρτιος
    return NAN; // Not A Number, ορίζεται στο math.h
  }

  double guess = x;
  double epsilon = 0.000001; // Όριο ακρίβειας
  double delta;
  do {
    double nx_minus_1 = pow(guess, n - 1);
    delta = (x - nx_minus_1 * guess) / (n * nx_minus_1);
    guess += delta;
  } while (fabs(delta) > epsilon);
  return guess;
}

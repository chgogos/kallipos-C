#include "logic.h"

int count_overlapping(Interval intervals[], int size, Interval target) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (overlap(intervals[i], target)) {
      count++;
    }
  }
  // Αφαιρούμε 1 από το πλήθος γιατί ο target δεν πρέπει να συγκριθεί με τον
  // εαυτό του
  return count - 1;
}

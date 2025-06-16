#include "ch14_e3_array.h"

int find_index(int *array, int size, int element) {
  for (int i = 0; i < size; i++) {
    if (array[i] == element) {
      return i;
    }
  }
  return -1; // Επιστρέφει -1 αν το στοιχείο δεν βρεθεί
}

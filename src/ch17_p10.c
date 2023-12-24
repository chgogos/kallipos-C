#include <stdio.h>
#include <stdlib.h>

// Συνάρτηση σύγκρισης για την qsort και την bsearch
int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main(void) {
  int array[10] = {20, 5, 10, 3, 15, 7, 30, 25, 1, 40};
  int key = 25; // Το στοιχείο που αναζητούμε
  int *found;

  // Ταξινόμηση του πίνακα με την qsort
  qsort(array, 10, sizeof(int), cmp);

  printf("Ταξινομημένος πίνακας: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // Δυαδική αναζήτηση με την bsearch
  found = (int *)bsearch(&key, array, 10, sizeof(int), cmp);

  if (found != NULL) {
    printf("Το στοιχείο %d βρέθηκε στη θέση %ld.\n", key,
           (found - array)); // ή found - &array[0]
  } else {
    printf("Το στοιχείο %d δεν βρέθηκε.\n", key);
  }

  return 0;
}

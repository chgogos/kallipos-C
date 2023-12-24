#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ταξινόμηση με εισαγωγή
void insertion_sort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// εκτύπωση των δύο πρώτων και των δύο τελευταίων στοιχείων του πίνακα
void print_array(int arr[], int n) {
  assert(n >= 4); // ο πίνακας πρέπει να έχει τουλάχιστον 4 στοιχεία
  printf("%d %d ... %d %d\n", arr[0], arr[1], arr[n - 2], arr[n - 1]);
}

int main(void) {
  srand(time(NULL));
  int N[] = {10000, 1000, 100};
  for (int k = 0; k < 3; k++) {
    int *a = malloc(sizeof(int) * N[k]);
    for (int i = 0; i < N[k]; i++) {
      a[i] = rand() % 1000;
    }
    insertion_sort(a, N[k]);
    print_array(a, N[k]);
    free(a);
  }
}

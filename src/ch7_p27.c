#include <stdio.h>

int main(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  int i;
  // Χρησιμοποιώντας δεικτοδότηση πίνακα
  printf("Using array indexing:\n");
  for (i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  // Χρησιμοποιώντας αριθμητική δεικτών στον πίνακα
  printf("Using array pointer arithmetic:\n");
  for (i = 0; i < 5; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
  return 0;
}

#include <stdio.h>

int main(void) {
  int numbers[10] = {4, 8, 15, 16, 23, 8, 9, 15, 16, 6};
  int key, i, found = 0;
  printf("Enter the key you want to search for: ");
  scanf("%d", &key);
  for (i = 0; i < 10; i++) {
    if (numbers[i] == key) {
      found = 1;
      break;
    }
  }
  if (found) {
    printf("Key %d found at index %d\n", key, i);
  } else {
    printf("Key not found in the array.\n");
  }
  return 0;
}

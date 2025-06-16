#include <stdio.h>

int main(void) {
  char string[11]; // buffer αποθήκευσης χαρακτήρων εισόδου (μαζί με το '\0')
  printf("Input text:");
  fgets(string, 11, stdin);
  printf("You entered:|%s|\n", string);

  return 0;
}

#include <stdio.h>

int main(void) {
  printf("Enter a character: ");
  int ch = getc(stdin); // Ανάγνωση ενός χαρακτήρα από το stdin
  printf("You entered: ");
  putc(ch, stdout); // Εγγραφή ενός χαρακτήρα στο stdout
  printf("\nYou entered '%c' which is at ASCII position %d (display using "
         "printf)\n",
         ch, ch); // Μορφοποιημένο μήνυμα με την printf
  return 0;
}

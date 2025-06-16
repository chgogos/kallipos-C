#include <stdio.h>

int main(void) {
  int num = 42;
  float pi = 3.14159f;
  char ch = 'A';
  char str[] = "Hello, World!"; // Αλφαριθμητικό
  printf("Integer: %d\n", num); // Εκτύπωση ενός ακεραίου
  printf("Float: %f\n", pi);    // Εκτύπωση ενός float
  printf("Character and its int value: %c %d\n", ch,
         ch); // Εκτύπωση χαρακτήρα και της αριθμητικής του τιμής
  printf("String: %s\n", str); // Εκτύπωση ενός λεκτικού
  printf("Octal: %o Hexadecimal: %x\n", num,
         num); // Εκτύπωση ακεραίου σε οκταδική και δεκαεξαδική μορφή
  printf("Width and Padding : %8d\n", num); // Εκτύπωση με καθορισμό πλάτους
  printf("Padding with zeros: %08d\n", num); // Εκτύπωση με καθορισμό πλάτους
  printf("Precision: %.2f\n", pi); // Εκτύπωση με καθορισμό ακρίβειας
  printf("Left-alignment : |%-20s|\n", str); // Αριστερή στοίχιση
  printf("Right-alignment: |%20s|\n", str);  // Δεξιά στοίχιση
  printf("Print %% character: %%\n"); // Εκτύπωση του χαρακτήρα %
  return 0;
}

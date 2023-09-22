#include <stdio.h>

int main(void) {
  unsigned int a = 12; // Δυαδικός: 1100
  unsigned int b = 10; // Δυαδικός: 1010
  unsigned int resultAnd = a & b;
  printf("Bitwise AND: %u\n", resultAnd); // Αποτέλεσμα: 8 (1000)
  unsigned int resultOr = a | b;
  printf("Bitwise OR: %u\n", resultOr); // Αποτέλεσμα: 14 (1110)
  unsigned int resultXor = a ^ b;
  printf("Bitwise XOR: %u\n", resultXor); // Αποτέλεσμα: 6 (110)
  unsigned int resultNotA = ~a;
  printf(
      "Bitwise NOT on %u: %u\n", a,
      resultNotA); // Αποτέλεσμα: 4294967283 (11111111111111111111111111110011)
  unsigned int resultLeftShift = a << 2;
  printf("Left Shift: %u\n", resultLeftShift); // Αποτέλεσμα: 48 (110000)
  unsigned int resultRightShift = b >> 1;
  printf("Right Shift: %u\n", resultRightShift); // Αποτέλεσμα: 5 (101)
  return 0;
}

#include <stdio.h>

void print_binary(unsigned int num) {
  int bits = sizeof(unsigned int) * 8;
  for (int i = bits - 1; i >= 0; i--) {
    unsigned int mask = 1u << i; // Δημιουργία μάσκας με 1 στην τρέχουσα θέση
    unsigned int bit = (num & mask) >> i; // Εξαγωγή της τιμής του τρέχοντος bit
    printf("%u", bit);
  }
  printf("\n");
}

int main(void) {
  unsigned int flags = 0;
  print_binary(flags);     // ...0000
  unsigned int flagA = 1; // Bit 0
  unsigned int flagB = 2; // Bit 1
  unsigned int flagC = 4; // Bit 2
  unsigned int flagD = 8; // Bit 3
  // Ορισμός flags με bitwise OR και μάσκας bits
  flags |= flagA;
  flags |= flagB;
  flags |= flagD;
  print_binary(flags); // ...1011
  // Έλεγχος αν ένα flag έχει τεθεί με bitwise AND και μάσκα bits
  printf((flags & flagB) ? "Flag B is set.\n" : "Flag B is not set.\n");
  // Εκκαθάριση ενός flag με bitwise AND και μάσκα bits
  flags &= ~flagA;
  print_binary(flags); // ...1010
  // Αλλαγή κατάστασης ενός flag με bitwise XOR και μάσκα bits
  flags ^= flagC;
  print_binary(flags); // ...1110
  // Έλεγχος αν ορισμένα flags έχουν τεθεί
  printf((flags & (flagB | flagC)) == (flagB | flagC)
             ? "Flag B, and flag C are set.\n"
             : "Either flag B or flag C are not set.\n");
  return 0;
}

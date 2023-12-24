#include <stdio.h>
#include <string.h>

int from_binary(char *s) {
  int length = strlen(s);
  int value = 0;

  // Διατρέχουμε το αλφαριθμητικό από το τέλος προς την αρχή
  for (int i = 0; i < length; i++) {
    // Αν το ψηφίο είναι '1', τότε προσθέτουμε στη δεκαδική τιμή το 2^i
    if (s[length - 1 - i] == '1') {
      value += (1 << i);
    }
  }

  return value;
}

int main(void) {
  char binary_string[] = "1110";
  int decimal_value = from_binary(binary_string);
  printf("Η δεκαδική τιμή του %s είναι %d.\n", binary_string, decimal_value);

  return 0;
}

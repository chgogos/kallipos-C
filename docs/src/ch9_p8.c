#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Υπολογισμός αριθμού δυαδικών ψηφίων του n
int count_binary(int n) {
  int count = 0;
  while (n != 0) {
    n = n / 2;
    count++;
  }
  return count;
}

// Μετατροπή ενός ακεραίου σε δυαδική μορφή
void convert(int n, char *b) {
  int pos = 0;
  while (n != 0) {
    b[pos++] = '0' + (n % 2);
    n = n / 2;
  }
  b[pos] = '\0';
}

// Αντιστροφή μιας συμβολοσειράς
void reverse(char *b) {
  int length = strlen(b);
  for (int i = 0; i < length / 2; i++) {
    char temp = b[i];
    b[i] = b[length - i - 1];
    b[length - i - 1] = temp;
  }
}

int main(void) {
  int number;
  char *binary;
  printf("Input a positive number: ");
  scanf("%d", &number);
  int digits = count_binary(number);
  binary = malloc((digits + 1) * sizeof(char));
  convert(number, binary);
  reverse(binary);
  printf("Binary representation of %d: %s\n", number, binary);
  free(binary);
  return 0;
}

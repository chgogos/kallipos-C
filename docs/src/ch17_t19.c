#include <stdio.h>
#include <string.h>

int main() {
  char source[] = "Never trust a computer you can't throw out a window";
  char destination[80];
  // αρχικοποίηση του destination με '*'
  memset(destination, '*', 79);
  destination[79] = '\0';
  printf("After memset, the destination is:\n%s\n", destination);
  // αντιγραφή δεδομένων από το source στο destination (ξεκινώντας την αντιγραφή
  // από τη θέση 10 του destination)
  memcpy(destination + (80 - strlen(source)) / 2, source, strlen(source));
  printf("After memcpy, the destination is:\n%s\n", destination);
  // σύγκριση περιεχομένων θέσεων μνήμης
  char *buffer = "BAD";
  for (int i = 0; i < strlen(buffer); i++) {
    int cmp_result = memcmp(buffer, buffer + i, strlen(buffer + i));
    if (cmp_result == 0) {
      printf("%s and %s are equal.\n", buffer, buffer + i);
    } else if (cmp_result < 0) {
      printf("%s is less than %s.\n", buffer, buffer + i);
    } else {
      printf("%s is greater than %s.\n", buffer, buffer + i);
    }
  }
  return 0;
}

#include <stdio.h>
#include <string.h>

int main(void) {
  const char *source =
      "Controlling complexity is the essence of computer programming.";
  char result[80] = "";
  // αντιγραφή των 22 πρώτων χαρακτήρων από το source στο result
  printf("Original=%s\n", source);
  strncpy(result, source, 22);
  printf("Partially copied=%s\n", result);
  // συνένωση των πρώτων 5 χαρακτήρων του source στο result
  strncat(result, source + 22,
          4); // συνένωση του " is " στο τέλος του result
  strncat(result, source + 50,
          12); // συνένωση του " programming." στο τέλος του result
  printf("Concatenated=%s\n", result);
  // σύγκριση τμημάτων λεκτικών
  printf("Comparisons using the first 2 letters of each string:\n");
  char *buffer[] = {"ABCD", "ABEF", "BCDE"};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int cmp_result = strncmp(buffer[i], buffer[j], 2);
      if (cmp_result == 0) {
        printf("%s and %s are equal.\n", buffer[i], buffer[j]);
      } else if (cmp_result < 0) {
        printf("%s is less than %s.\n", buffer[i], buffer[j]);
      } else {
        printf("%s is greater than %s.\n", buffer[i], buffer[j]);
      }
    }
  }
  return 0;
}

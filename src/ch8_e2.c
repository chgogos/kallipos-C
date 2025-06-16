#include <stdio.h>
#include <string.h>

// Υπολογίζει τον αριθμό των κοινών χαρακτήρων μεταξύ δύο αλφαριθμητικών
int count_common_chars(const char *str1, const char *str2) {
  int common_chars = 0;
  for (int i = 0; str1[i] != '\0'; i++) {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        common_chars++;
        break;
      }
    }
  }
  return common_chars;
}

int main(void) {
  char str1[100], str2[100];
  printf("Enter first string: ");
  fgets(str1, sizeof(str1), stdin);
  str1[strcspn(str1, "\n")] =
      '\0'; // Αφαιρεί το newline που προστίθεται από το fgets

  printf("Enter second string: ");
  fgets(str2, sizeof(str2), stdin);
  str2[strcspn(str2, "\n")] =
      '\0'; // Αφαιρεί το newline που προστίθεται από το fgets

  printf("Common characters: %d\n", count_common_chars(str1, str2));
  return 0;
}

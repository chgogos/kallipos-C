#include <stdio.h>
#include <string.h>

// Διαγράφει τον χαρακτήρα στη θέση `position` του αλφαριθμητικού `str`
void delete_char_at_position(char *str, int position) {
  int length = strlen(str);
  // Έλεγχος εγκυρότητας της θέσης
  if (position < 0 || position >= length) {
    printf("Invalid position.\n");
    return;
  }
  // Αντιγραφή των χαρακτήρων μία θέση προς τα αριστερά
  for (int i = position; i < length - 1; i++) {
    str[i] = str[i + 1];
  }
  // Τοποθέτηση του τελευταίου χαρακτήρα ως null terminator
  str[length - 1] = '\0';
}

int main(void) {
  char str[100];
  int position;
  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);
  // Αφαίρεση του newline χαρακτήρα που προστίθεται από την fgets
  str[strcspn(str, "\n")] = '\0';
  printf("Enter the position of the character you want to delete: ");
  scanf("%d", &position);
  delete_char_at_position(str, position);
  printf("Resulting string: %s\n", str);
  return 0;
}

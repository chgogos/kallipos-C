#include <stdio.h>
#include <string.h>

int main(void) {
  char x[20], y[10];
  printf("Input text: ");
  fgets(x, 10, stdin); // Διάβασε το πολύ 9 χαρακτήρες από το πληκτρολόγιο
  x[strcspn(x, "\n")] = '\0'; // Αφαιρούμε τον χαρακτήρα νέας γραμμής
  fflush(stdin); // Αδειάζουμε τον buffer του πληκτρολογίου
  printf("Input another text: ");
  fgets(y, 10, stdin);
  y[strcspn(y, "\n")] = '\0'; 
  strcat(x, y);
  printf("The concatenated text is: %s\n", x);
  return 0;
}

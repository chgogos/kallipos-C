#include <stdio.h>
#include <string.h>

int main(void) {
  char s1[10], s2[10];
  printf("Input a string: ");
  fgets(s1, 10, stdin);
  s1[strcspn(s1, "\n")] = '\0'; // Αφαιρούμε το χαρακτήρα νέας γραμμής
  fflush(stdin); // Αδειάζουμε τον buffer του stdin
  printf("Input another string: ");
  fgets(s2, 10, stdin);
  s2[strcspn(s2, "\n")] = '\0'; 
  printf("The first string is: %s\n", s1);
  printf("The second string is: %s\n", s2);
  return 0;
}

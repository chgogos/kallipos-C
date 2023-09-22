#include <stdio.h>

int main(void) {
  float x = 5 / 2; // Ακέραια διαίρεση
  printf("%.1f\n", x);
  x = (float)5 / (float)2; // Διαίρεση με πραγματικό αποτέλεσμα
  printf("%.1f\n", x);
  return 0;
}

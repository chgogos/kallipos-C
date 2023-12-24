#include <stdio.h>
#include <string.h>

#define SIZE 5

int main(void) {
  char names[SIZE][20] = {"Dennis", "Ken", "Brian", "Stephen", "Bjarne"};
  char temp[20];
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE - 1; j++) {
      if (strcmp(names[j], names[j + 1]) > 0) {
        strcpy(temp, names[j]);
        strcpy(names[j], names[j + 1]);
        strcpy(names[j + 1], temp);
      }
    }
  }
  for (int i = 0; i < SIZE; i++) {
    printf("%s\n", names[i]);
  }
  return 0;
}

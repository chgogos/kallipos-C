#include <stdio.h>

int main(void) {
  int age;
  char grade;
  printf("Enter age and grade:");
  scanf("%d", &age);
  scanf("%c", &grade);
  printf("Age=%d Grade=%c\n", age, grade);
  return 0;
}

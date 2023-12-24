#include <stdio.h>

int main(void) {
  char input_string[] = "Jane Doe 25";
  char first_name[20];
  char last_name[20];
  int age;

  int r = sscanf(input_string, "%s %s %d", first_name, last_name, &age);
  if (r == EOF) {
    printf("Error in parsing input data\n");
  } else {
    printf("%d values read.\n", r);
    printf("First Name: %s, Last Name: %s, Age: %d\n", first_name, last_name,
           age);
  }
  return 0;
}

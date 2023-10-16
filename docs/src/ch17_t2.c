#include <stdio.h>

int main(void) {
  char output_string[100];
  int a = 10;
  float b = 2.73f;
  double c = 3.14;
  int d = sprintf(output_string, "a=%d, b=%.2f, c=%.2lf", a, b, c);
  printf("Characters written=%d\n", d);
  printf("%s\n", output_string);
  return 0;
}

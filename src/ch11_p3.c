#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc != 4) {
    printf("Usage: %s <operator> <operand1> <operand2>\n", argv[0]);
    printf("Example: %s ADD 1.4 2.7\n", argv[0]);
    printf("Result: %lf\n", 1.4 + 2.7);
    return EXIT_FAILURE;
  }
  double v1 = atof(argv[2]);
  double v2 = atof(argv[3]);
  double result = .0;
  if (!strcmp(argv[1], "ADD")) {
    result = v1 + v2;
  } else if (!strcmp(argv[1], "SUB")) {
    result = v1 - v2;
  } else if (!strcmp(argv[1], "MUL")) {
    result = v1 * v2;
  } else if (!strcmp(argv[1], "DIV")) {
    result = v1 / v2;
  }
  printf("Result: %lf \n", result);
  return 0;
}

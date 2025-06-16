#include "math_functions.h"
#include "utils.h"

int main(void) {
  int a = 10, b = 5;
  print_message("Calculator App");
  int sum = add(a, b);
  int product = multiply(a, b);
  print_result("Addition", sum);
  print_result("Multiplication", product);
  return 0;
}

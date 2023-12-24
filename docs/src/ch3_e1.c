#include <math.h>
#include <stdio.h>

int main(void) {
  int choice;
  const char *function_name;

  printf("Trigonometric Functions\n");
  printf("=======================\n");
  printf("1. Sine\n");
  printf("2. Cosine\n");
  printf("3. Tangent\n");
  printf("Enter your choice (1-3): ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    function_name = "Sine";
    break;
  case 2:
    function_name = "Cosine";
    break;
  case 3:
    function_name = "Tangent";
    break;
  default:
    printf("Invalid choice.\n");
    return 1;
  }

  printf("\n");
  printf("D       %-12s   D       %-12s   D       %-12s\n", function_name,
         function_name, function_name);
  printf("====================================================================="
         "===\n");

  for (int angle = 1; angle <= 360; angle++) {
    double radians = angle * (M_PI / 180.0);
    double value;

    switch (choice) {
    case 1:
      value = sin(radians);
      break;
    case 2:
      value = cos(radians);
      break;
    case 3:
      if (angle % 90 == 0) {
        value = NAN;
      } else {
        value = tan(radians);
      }
      break;
    }

    printf("%-6d   %-12.4f   ", angle, value);

    if (angle % 3 == 0)
      printf("\n");
  }
  return 0;
}

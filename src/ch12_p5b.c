#include <stdio.h>

#define DECLARE_WITH_COPY(type, name, value)                                   \
  type name = value;                                                           \
  type name##_copy = name;

int main(void) {
  DECLARE_WITH_COPY(double, speed, 60);
  speed *= 1.2;
  printf("SPEED = %.2f\n", speed);
  printf("SPEED (original) = %.2f\n", speed_copy);
}

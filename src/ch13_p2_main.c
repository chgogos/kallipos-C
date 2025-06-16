#include <ch13_p2_geom.h>
#include <stdio.h>

int main(void) {
  point p1 = {3.0, 4.0};
  point p2 = {6.0, 8.0};
  double d = distance(p1, p2);
  printf("The distance between (%.1f, %.1f) "
         "and (%.1f, %.1f) is %.1f\n",
         p1.x, p1.y, p2.x, p2.y, d);
}

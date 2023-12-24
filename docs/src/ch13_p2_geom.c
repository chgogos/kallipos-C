#include <ch13_p2_geom.h>
#include <math.h>

double distance(point p1, point p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}

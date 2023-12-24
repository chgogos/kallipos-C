#include "ch13_p1_utility.h"
#include <math.h>

double distance(double lat1, double lon1, double lat2, double lon2) {
  if ((lat1 == lat2) && (lon1 == lon2)) {
    return 0;
  } else {
    double theta, dist;
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) +
           cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.853159616;
    return dist;
  }
}

double deg2rad(double deg) { return deg * PI / 180; }
double rad2deg(double rad) { return rad * 180 / PI; }

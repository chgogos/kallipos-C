// https://www.baeldung.com/cs/finding-all-overlapping-intervals

#include "interval.h"

int overlap(Interval int1, Interval int2) {
  return MAX(int1.x, int2.x) < MIN(int1.y, int2.y);
}

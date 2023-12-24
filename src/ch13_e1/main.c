#include "interval.h"
#include "logic.h"
#include <stdio.h>

int main(void) {
  int n;
  printf("Enter number of intervals: ");
  scanf("%d", &n);

  Interval intervals[n];

  for (int i = 0; i < n; i++) {
    printf("Enter space-separated start and end for interval %d: ", i);
    scanf("%d %d", &intervals[i].x, &intervals[i].y);
  }

  for (int i = 0; i < n; i++) {
    int count = count_overlapping(intervals, n, intervals[i]);
    printf("Interval [%d, %d) has %d overlapping intervals.\n", intervals[i].x,
           intervals[i].y, count);
  }

  return 0;
}

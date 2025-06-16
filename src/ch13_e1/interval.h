#ifndef INTERVAL_H
#define INTERVAL_H
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

typedef struct {
  int x;
  int y;
} Interval;

int overlap(Interval int1, Interval int2);

#endif

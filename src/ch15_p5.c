#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct point {
  double x;
  double y;
};

double distance(struct point *p1, struct point *p2) {
  return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

double randfrom(double min, double max) {
  return min + rand() / RAND_MAX * (max - min);
}

void fill_vector(struct point **points, int N) {
  srand(1234); // χρήση seed για επαναληψιμότητα αποτελεσμάτων
  for (int i = 0; i < N; i++) {
    points[i] = malloc(sizeof(struct point));
    points[i]->x = randfrom(-100, 100);
    points[i]->y = randfrom(-100, 100);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <number_of_points>\n", argv[0]);
    return -1;
  }
  struct point origin = {0.0, 0.0};
  const int N = atoi(argv[1]);
  struct point **points = malloc(
      N *
      sizeof(struct point)); // δέσμευση μνήμης για N δείκτες σε struct point
  fill_vector(points, N);
  for (int i = 0; i < N; i++) {
    double d = distance(points[i], &origin);
    printf("point%d=(%+06.2f,%+06.2f) distance from origin=%6.2f\n", i,
           points[i]->x, points[i]->y, d);
  }
  for (int i = 0; i < N; i++) {
    free(points[i]);
  }
  free(points);
  return 0;
}

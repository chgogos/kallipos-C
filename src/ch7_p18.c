#include <stdio.h>

void try1(int *x) {
  printf("BEFORE x=%p\n", (void *)x);
  x++;
  printf("AFTER x=%p\n", (void *)x);
}

void try2(int **x) { (*x)++; }

int main(void) {
  int x[] = {10, 20, 30, 40, 50};
  int *pt1 = &x[2];
  int *pt2 = &x[2];
  printf("pt1=%p, pt2=%p\n", (void *)pt1, (void *)pt2);

  try1(pt1);
  *pt1 = *pt1 + 1;
  for (int i = 0; i < 5; i++) {
    printf("%p=%d ", (void *)&x[i], x[i]);
  }
  printf("\n");

  try2(&pt2); // καλείται με τη διεύθυνση του δείκτη pt2
  *pt2 = *pt2 + 1;
  for (int i = 0; i < 5; i++) {
    printf("%p=%d ", (void *)&x[i], x[i]);
  }
  printf("\n");
  // δείκτης pt1 δεν αλλάζει περιεχόμενο ενώ ο δείκτης pt2 αλλάζει
  printf("pt1=%p, pt2=%p\n", (void *)pt1, (void *)pt2);
  return 0;
}

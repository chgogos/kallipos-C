/*
 * Κώδικας από το https://www.unix-ag.uni-kl.de/~conrad/shocc/example.c
 * με μικρές τροποποιήσεις
 */
#include <stdio.h>
#include <stdlib.h>

void o(int n) { printf("%d ", n); }

int main(int argc, char *argv[]) {
  int i1, i2, i, increment;

  if (argc != 3) {
    printf("Wrong number of arguments!\n");
    return -1;
  }

  i1 = atoi(argv[1]);
  i2 = atoi(argv[2]);

  if (i1 < i2) {
    increment = 1;
  } else {
    increment = -1;
  }

  for (i = i1; i != i2; i = i + increment) {
    o(i);
  }

  o(i2);
  return 0;
}

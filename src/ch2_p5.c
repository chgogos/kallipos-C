#include <stdio.h>

int main(void) {
  int i1;
  long i2;
  float f1;
  double f2;
  char s[20];
  printf("Enter 2 int values : ");
  scanf("%d", &i1);
  scanf("%ld", &i2);
  printf("i1=%d, i2=%ld\n", i1, i2);
  printf("Enter 2 float values : ");
  scanf("%f %lf", &f1, &f2);
  printf("f1=%f, f2=%lf\n", f1, f2);
  printf("Enter a string: ");
  scanf("%s", s);
  printf("s=%s\n", s);
  return 0;
}

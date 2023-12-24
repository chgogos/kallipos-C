#include <stdio.h>

typedef union {
  int ival;
  float fval;
  double dval;
} itype;

int main(void) {
  itype var;
  var.ival = 100;
  printf("Integer value :%d \n", var.ival);
  var.fval = 22.56;
  printf("Float value: %f \n", var.fval);
  var.dval = 1929.37;
  printf("Double value: %lf \n", var.dval);
  printf("Now integer value: %d\n", var.ival);
  return 0;
}

#include <stdio.h>
#define INTTYPE 1
#define FLOATTYPE 2
#define DOUBLETYPE 3

typedef unsigned char byte;

typedef union {
  int ival;
  float fval;
  double dval;
} itype;

typedef struct {
  itype value;
  byte flag;
} number;

number read_number(byte flag) {
  number x;
  x.flag = flag;
  switch (flag) {
  case INTTYPE:
    scanf("%d", &x.value.ival);
    break;
  case FLOATTYPE:
    scanf("%f", &x.value.fval);
    break;
  case DOUBLETYPE:
    scanf("%lf", &x.value.dval);
    break;
  }
  return x;
}

void print_number(number x) {
  switch (x.flag) {
  case INTTYPE:
    printf("Integer: %d\n", x.value.ival);
    break;
  case FLOATTYPE:
    printf("Float: %f\n", x.value.fval);
    break;
  case DOUBLETYPE:
    printf("Double: %lf\n", x.value.dval);
    break;
  }
}

int main(void) {
  number a_number;
  printf("Input an int: ");
  a_number = read_number(INTTYPE);
  print_number(a_number);
  printf("Input a double: ");
  a_number = read_number(DOUBLETYPE);
  print_number(a_number);
  return 0;
}

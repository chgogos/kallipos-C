#include <stdio.h>

int main(void) {
  int num1 = 10, num2 = 7, num3 = 15;
  int max12 = (num1 > num2) ? num1 : num2; // εύρεση μεγίστου 2 τιμών
  printf("num1=%d, num2=%d, max=%d\n", num1, num2, max12);
  int max123 = (num1 > num2)
                   ? ((num1 > num3) ? num1 : num3)
                   : ((num2 > num3) ? num2 : num3); // εύρεση μεγίστου 3 τιμών
  printf("num1=%d, num2=%d, num3=%d, max=%d\n", num1, num2, num3, max123);
  return 0;
}

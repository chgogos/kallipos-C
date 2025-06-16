#include <math.h>
#include <stdio.h>

int main(void) {
  double initialQuantity, targetQuantity;
  int count = 0;

  printf("Enter the initial quantity: ");
  scanf("%lf", &initialQuantity);
  printf("Enter the target quantity: ");
  scanf("%lf", &targetQuantity);

  // Υπολογισμός μέσω επανάληψης
  double currentQuantity = initialQuantity;
  while (currentQuantity > targetQuantity) {
    currentQuantity /= 2;
    count++;
  }

  printf("It took %d halvings to make the quantity equal to or less than the "
         "target.\n",
         count);

  // Υπολογισμός μέσω λογαριθμικής συνάρτησης
  int logCount = (int)ceil(log(initialQuantity / targetQuantity) / log(2));

  printf("The logarithmic calculation shows that %d halvings are needed.\n",
         logCount);

  return 0;
}

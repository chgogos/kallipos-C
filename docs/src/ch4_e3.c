#include <stdio.h>

int is_palindromic(int number) {
  int reversed = 0;
  int original = number; // Αποθηκεύστε τον αρχικό αριθμό για τον έλεγχο

  while (number != 0) {
    int digit = number % 10;
    reversed = reversed * 10 + digit;
    number /= 10;
  }

  return original == reversed;
}

int main(void) {
  int num;
  printf("Εισάγετε έναν αριθμό: ");
  scanf("%d", &num);
  if (is_palindromic(num)) {
    printf("Ο αριθμός %d είναι παλινδρομικός.\n", num);
  } else {
    printf("Ο αριθμός %d δεν είναι παλινδρομικός.\n", num);
  }
  return 0;
}

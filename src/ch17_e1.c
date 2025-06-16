#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int lower_bound = 1;
  int upper_bound = 100;
  int secret_number, guess;
  int attempts = 0;
  srand(time(NULL));
  secret_number = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;
  printf("I have picked a number between %d and %d. Try to guess it!\n",
         lower_bound, upper_bound);
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    attempts++;
    if (guess == secret_number) {
      printf("Congratulations! You guessed the correct number %d in %d "
             "attempts.\n",
             secret_number, attempts);
      break;
    } else if (guess < secret_number) {
      printf("Try a higher number.\n");
    } else {
      printf("Try a lower number.\n");
    }
  } while (1);
  return 0;
}

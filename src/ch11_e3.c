#include <stdbool.h>
#include <stdio.h>

bool is_prime(int num) {
  if (num <= 1)
    return false;
  if (num % 2 == 0 && num > 2)
    return false;
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0)
      return false;
  }
  return true;
}

void display_file_contents(const char *filename) {
  FILE *file = fopen(filename, "r");
  int num;

  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  printf("Contents of %s:\n", filename);
  while (fscanf(file, "%d", &num) != EOF) {
    printf("%d\n", num);
  }

  fclose(file);
}

int main(void) {
  int num;
  FILE *file = fopen("primes.txt", "w");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  printf("Enter numbers (0 to stop): ");
  while (1) {
    scanf("%d", &num);
    if (num == 0)
      break;

    if (is_prime(num)) {
      fprintf(file, "%d\n", num);
      printf("%d is a prime number and has been added to the file.\n", num);
    }
  }

  fclose(file);

  // Display the contents of primes.txt before exiting
  display_file_contents("primes.txt");

  return 0;
}

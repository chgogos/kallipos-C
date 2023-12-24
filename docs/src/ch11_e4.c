#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBERS_COUNT 1000000
#define FILENAME_TEXT "numbers.txt"
#define FILENAME_BINARY "numbers.bin"

void write_numbers_to_text_file(int *numbers, const char *filename) {
  clock_t start = clock();
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error opening file for writing");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < NUMBERS_COUNT; i++) {
    fprintf(file, "%d%s", numbers[i], (i < NUMBERS_COUNT - 1) ? "," : "\n");
  }

  fclose(file);
  clock_t end = clock();
  printf("Time taken to write to text file: %.6f seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);
}

void write_numbers_to_binary_file(int *numbers, const char *filename) {
  clock_t start = clock();
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    perror("Error opening file for writing");
    exit(EXIT_FAILURE);
  }

  fwrite(numbers, sizeof(int), NUMBERS_COUNT, file);

  fclose(file);
  clock_t end = clock();
  printf("Time taken to write to binary file: %.6f seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);
}

void read_numbers_from_text_file(const char *filename) {
  clock_t start = clock();
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file for reading");
    exit(EXIT_FAILURE);
  }

  int number;
  char comma;
  long sum = 0;
  while (fscanf(file, "%d%c", &number, &comma) == 2) {
    sum += number;
  }
  printf("Average: %.2f\n", (double)sum / NUMBERS_COUNT);

  fclose(file);
  clock_t end = clock();
  printf("Time taken to read from text file: %.6f seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);
}

void read_numbers_from_binary_file(const char *filename) {
  clock_t start = clock();
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file for reading");
    exit(EXIT_FAILURE);
  }

  int numbers[NUMBERS_COUNT];
  fread(numbers, sizeof(int), NUMBERS_COUNT, file);
  long sum = 0;
  for (int i = 0; i < NUMBERS_COUNT; i++) {
    sum += numbers[i];
  }
  printf("Average: %.2f\n", (double)sum / NUMBERS_COUNT);

  fclose(file);
  clock_t end = clock();
  printf("Time taken to read from binary file: %.6f seconds\n",
         (double)(end - start) / CLOCKS_PER_SEC);
}

int main(void) {
  int numbers[NUMBERS_COUNT];
  for (int i = 0; i < NUMBERS_COUNT; i++) {
    numbers[i] = rand() % 100;
  }

  write_numbers_to_text_file(numbers, FILENAME_TEXT);
  read_numbers_from_text_file(FILENAME_TEXT);

  write_numbers_to_binary_file(numbers, FILENAME_BINARY);
  read_numbers_from_binary_file(FILENAME_BINARY);

  return 0;
}

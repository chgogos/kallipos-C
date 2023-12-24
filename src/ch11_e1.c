#include <ctype.h>
#include <stdio.h>

int main() {
  char filename[100];
  printf("Enter the name of the text file: ");
  scanf("%99s", filename);

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  int total_chars = 0;
  int uppercase_chars = 0;
  char ch;

  while ((ch = fgetc(file)) != EOF) {
    if (isalpha(ch)) {
      total_chars++;
      if (isupper(ch)) {
        uppercase_chars++;
      }
    }
  }

  if (total_chars == 0) {
    printf("No alphabetic characters found in the file.\n");
  } else {
    double percentage = (double)uppercase_chars / total_chars * 100;
    printf("Percentage of uppercase characters: %.2f%%\n", percentage);
  }

  fclose(file);
  return 0;
}

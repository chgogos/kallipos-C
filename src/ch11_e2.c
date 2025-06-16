#include <ctype.h>
#include <stdbool.h>
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

  char
      line[1024]; // Θεωρούμε ότι κάθε γραμμή έχει μέγιστο μήκος 1023 χαρακτήρων
  while (fgets(line, sizeof(line), file)) {
    if (isupper(line[0])) {
      printf("%s", line); // Εκτυπώνει τη γραμμή αν ξεκινάει με κεφαλαίο γράμμα
    }
  }

  fclose(file);
  return 0;
}

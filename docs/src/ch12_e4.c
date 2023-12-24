#include <stdio.h>
#include <stdlib.h>

#define FOPEN(filename, mode)                                                  \
  ({                                                                           \
    FILE *file = fopen(filename, mode);                                        \
    if (file == NULL) {                                                        \
      fprintf(stderr, "Error opening file %s\n", filename);                    \
      exit(EXIT_FAILURE);                                                      \
    }                                                                          \
    file;                                                                      \
  })

int main(void) {
  FILE *file = FOPEN("quotes.txt", "r");
  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), file)) {
    printf("%s", buffer);
  }
  fclose(file);
  return 0;
}

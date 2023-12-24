#include <stdio.h>
#include <string.h>

int main(void) {
  char *names[] = {"Mr. Chris", "Ms. Ada",   "George",  "Mr. John",
                   "Anna",      "Ms. Sofia", "Mr. Alex"};
  for (size_t i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
    printf("%s\n", names[i]);
  }
  return 0;
}

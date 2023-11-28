# Κεφάλαιο 2

## Εισαγωγικές έννοιες στον προγραμματισμό με τη C


```{.c title="ch2_p1.c" linenums="1"}
#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
  printf("int (%zu bytes)\t\t%d to %d\n", sizeof(int), INT_MIN, INT_MAX);
  printf("double (%zu bytes)\t%e to %e\n", sizeof(double), DBL_MIN, DBL_MAX);
  return 0;
}
```

```{.c title="ch2_p2.c" linenums="1"}
#include <stdio.h>

int main(void) {
  printf("This string contains newline characters \nNew Line\n");
  printf("This string contains a tab character \tTabbed Text\n");
  printf("This string contains a backslash character \\ \n");
  printf("This string contains \"Double Quotes\"\n");
  printf("This string contains \'Single Quotes\'\n");
  printf("This string contains backspace characters:Learn C++\b\b\bplain C\n");
  printf("This string makes a beep sound \a \n");
  printf("This string contains a hexadecimally encoded symbol \xFB \n");
  printf("This string contains the NULL character\0 unreached text");
  return 0;
}
```
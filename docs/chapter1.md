# Κεφάλαιο 1

## Hello World! :smile: στη C 


```{.c title="ch1_p1.c" linenums="1" hl_lines = "4"}
#include <stdio.h>

int main(void) {
  printf("Hello World!\n");
  return 0;
}
```

--8<-- "./src/ch1_p1.c"

<!-- [ch1_p1.c](./src/ch1_p1.c) -->

Μεταγλώττιση και εκτέλεση

```{.text .nocopy}
$ gcc ch1_p1.c
$ ./a.out
Hello World!
```


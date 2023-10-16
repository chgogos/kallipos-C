# Κεφάλαιο 1

## Η πορεία της C μέχρι σήμερα

## Hello World! :smile: στη C 

<!-- ```{.c title="ch1_p1.c" linenums="1" hl_lines = "4"}
#include <stdio.h>

int main(void) {
  printf("Hello World!\n");
  return 0;
}
``` -->

```{.c title="ch1_p1.c" linenums="1" hl_lines = "4"}
--8<-- "src/ch1_p1.c"
```

<!-- [ch1_p1.c](./src/ch1_p1.c) -->

Μεταγλώττιση και εκτέλεση σε Linux ή MacOS

```{.text .nocopy}
$ gcc ch1_p1.c
$ ./a.out
Hello World!
```

Μεταγλώττιση και εκτέλεση σε Windows

```{.text .nocopy}
> gcc ch1_p1.c
> a.exe
Hello World!
```

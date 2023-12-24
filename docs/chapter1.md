# Κεφάλαιο 1

<h1>Η πορεία της C μέχρι σήμερα</h1>

## 1.6 Συγγραφή μεταγλώττιση και εκτέλεση απλών προγραμμάτων

**Hello World! :smile: στη C** 

```{.c title="ch1_p1.c" linenums="1" hl_lines = "4"}
--8<-- "src/ch1_p1.c"
```

Μεταγλώττιση και εκτέλεση σε Linux

```{.text .nocopy}
$ gcc ch1_p1.c
$ ./a.out
Hello World!
```

Μεταγλώττιση και εκτέλεση σε MacOS

```{.text .nocopy}
% gcc ch1_p1.c
% ./a.out
Hello World!
```

Μεταγλώττιση και εκτέλεση σε Windows

```{.text .nocopy}
> gcc ch1_p1.c
> a.exe
Hello World!
```

### 1.6.1 Μεταγλώττιση με ενεργοποίηση warnings, διακόπτες μεταγλώττισης

```{.c title="ch1_p2.c" linenums="1"}
--8<-- "src/ch1_p2.c"
```

Μεταγλώττιση

```{.text .nocopy}
$ gcc ch1_p2.c -o ch1_p2 -std=c17 -Wall -Wextra -pedantic
./ch1_p2
ch1_p2.c:3:20: warning: unused parameter 'b' [-Wunused-parameter]
int fun(int a, int b) {
                   ^
ch1_p2.c:11:9: warning: zero size arrays are an extension [-Wzero-length-array]
  int z[0]; // πίνακας με μέγεθος μηδέν (εντοπίζεται με το -pedantic)
        ^
ch1_p2.c:10:7: warning: unused variable 'y' [-Wunused-variable]
  int y = 1729; // μεταβλητή που δεν χρησιμοποιείται (εντοπίζεται με το -Wall)
      ^
ch1_p2.c:11:7: warning: unused variable 'z' [-Wunused-variable]
  int z[0]; // πίνακας με μέγεθος μηδέν (εντοπίζεται με το -pedantic)
      ^
ch1_p2.c:13:18: warning: variable 'x' is uninitialized when used here [-Wuninitialized]
  printf("x=%d", x);
                 ^
ch1_p2.c:9:8: note: initialize the variable 'x' to silence this warning
  int x; // μεταβλητή που δεν έχει αρχικοποιηθεί (εντοπίζεται με το -Wall)
       ^
        = 0
5 warnings generated.
Hello World!
```
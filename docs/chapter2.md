# Κεφάλαιο 2

<h1>Εισαγωγικές έννοιες στον προγραμματισμό με τη C</h1>

## 2.2 Τύποι δεδομένων και μεταβλητές

```{.c title="ch2_p1.c" linenums="1"}
--8<-- "src/ch2_p1.c"
```

```{.text .nocopy}
$ gcc ch2_p1.c -o ch2_p1 -Wall -Wextra -pedantic -std=c17
$ ./ch2_p1
int (4 bytes)           -2147483648 to 2147483647
double (8 bytes)        2.225074e-308 to 1.797693e+308
```

## 2.5 Είσοδος / Έξοδος

### 2.5.1 Η συνάρτηση printf()

```{.c title="ch2_p2.c" linenums="1"}
--8<-- "src/ch2_p2.c"
```

```{.text .nocopy}
$ gcc ch2_p2.c -o ch2_p2 -Wall -Wextra -pedantic -std=c17
$ ./ch2_p2
This string contains newline characters 
New Line
This string contains a tab character    Tabbed Text
This string contains a backslash character \
This string contains "Double Quotes"
This string contains 'Single Quotes'
This string contains backspace characters:Learn plain C
This string makes a beep sound
This string contains a hexadecimally encoded symbol √
This string contains the NULL character
```

```{.c title="ch2_p3.c" linenums="1"}
--8<-- "src/ch2_p3.c"
```

```{.c title="ch2_p4.c" linenums="1"}
--8<-- "src/ch2_p4.c"
```

### 2.5.2 Η συνάρτηση scanf()
```{.c title="ch2_p5.c" linenums="1"}
--8<-- "src/ch2_p5.c"
```

### 2.5.3 Ιδιαιτερότητες της scanf() και άλλες συναρτήσεις εισόδου/εξόδου
```{.c title="ch2_p6.c" linenums="1"}
--8<-- "src/ch2_p6.c"
```

```{.c title="ch2_p7.c" linenums="1"}
--8<-- "src/ch2_p7.c"
```

#### Διαδοχικές scanf()
```{.c title="ch2_p8.c" linenums="1"}
--8<-- "src/ch2_p8.c"
```

#### Οι συναρτήσεις getc() και putc()
```{.c title="ch2_p9.c" linenums="1"}
--8<-- "src/ch2_p9.c"
```

## 2.6 Τελεστές

### 2.6.2 Αριθμητικοί τελεστές
```{.c title="ch2_p10.c" linenums="1"}
--8<-- "src/ch2_p10.c"
```

```{.c title="ch2_p11.c" linenums="1"}
--8<-- "src/ch2_p11.c"
```

### 2.6.3 Συγκριτικοί τελεστές
```{.c title="ch2_p12.c" linenums="1"}
--8<-- "src/ch2_p12.c"
```

### 2.6.4 Λογικοί τελεστές
```{.c title="ch2_p13.c" linenums="1"}
--8<-- "src/ch2_p13.c"
```

### 2.6.5 Τελεστές χειρισμού δυαδικών ψηφίων
```{.c title="ch2_p14.c" linenums="1"}
--8<-- "src/ch2_p14.c"
```

#### 2.6.5.1 Μάσκες δυαδικών ψηφίων
```{.c title="ch2_p15.c" linenums="1"}
--8<-- "src/ch2_p15.c"
```

### 2.6.6 Τελεστές μετατροπής τύπων
```{.c title="ch2_p16.c" linenums="1"}
--8<-- "src/ch2_p16.c"
```

### 2.6.7 Άλλοι τελεστές
```{.c title="ch2_p17.c" linenums="1"}
--8<-- "src/ch2_p17.c"
```

```{.c title="ch2_p18.c" linenums="1"}
--8<-- "src/ch2_p18.c"
```

```{.c title="ch2_p19.c" linenums="1"}
--8<-- "src/ch2_p19.c"
```

## 2.8 Κύκλος μεταγλώττισης, σύνδεσης και εκτέλεσης

```{.c title="ch2_p20.c" linenums="1"}
--8<-- "src/ch2_p20.c"
```

<!-- ## 2.9 Ασκήσεις

***Άσκηση 1***
```{.c title="ch2_e1.c" linenums="1"}
--8<-- "src/ch2_e1.c"
```

***Άσκηση 2***
```{.c title="ch2_e2.c" linenums="1"}
--8<-- "src/ch2_e2.c"
```

***Άσκηση 3***
```{.c title="ch2_e3.c" linenums="1"}
--8<-- "src/ch2_e3.c"
```

***Άσκηση 4***
```{.c title="ch2_e4.c" linenums="1"}
--8<-- "src/ch2_e4.c"
```

***Άσκηση 5***
```{.c title="ch2_e5.c" linenums="1"}
--8<-- "src/ch2_e5.c"
```
 -->

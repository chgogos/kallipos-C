# Κεφάλαιο 13

<h1>Διαμέριση κώδικα</h1>

## 13.2 Αρχεία επικαφαλίδων και αρχεία πηγαίου κώδικα στη C

### 13.2.2 Παράδειγμα διαχωρισμού διεπαφής και υλοποίησης

```{.txt title="geolocations.txt" linenums="1"}
--8<-- "src/geolocations.txt"
```

```{.c title="ch13_p1_utility.h" linenums="1"}
--8<-- "src/ch13_p1_utility.h"
```

```{.c title="ch13_p1_io.h" linenums="1"}
--8<-- "src/ch13_p1_io.h"
```

```{.c title="ch13_p1_utility.c" linenums="1"}
--8<-- "src/ch13_p1_utility.c"
```

```{.c title="ch13_p1_io.c" linenums="1"}
--8<-- "src/ch13_p1_io.c"
```

```{.c title="ch13_p1_main.c" linenums="1"}
--8<-- "src/ch13_p1_main.c"
```

## 13.4 Οργάνωση μεταγλώττισης με το make

### 13.4.1 Παραδείγματα με makefiles

```{.c title="ch13_p2_main.c" linenums="1"}
--8<-- "src/ch13_p2_main.c"
```

```{.c title="ch13_p2_geom.h" linenums="1"}
--8<-- "src/ch13_p2_geom.h"
```

```{.c title="ch13_p2_geom.c" linenums="1"}
--8<-- "src/ch13_p2_geom.c"
```

```{.mk title="ch13_p2_makefile1.mk" linenums="1"}
--8<-- "src/ch13_p2_makefile1.mk"
```

```{.mk title="ch13_p2_makefile2.mk" linenums="1"}
--8<-- "src/ch13_p2_makefile2.mk"
```

```{.mk title="ch13_p2_makefile3.mk" linenums="1"}
--8<-- "src/ch13_p2_makefile3.mk"
```


<!-- ## 13.5 Ασκήσεις

***Άσκηση 1***

***Άσκηση 2***

***Άσκηση 3***

***Άσκηση 4*** -->

# Κεφάλαιο 20

<h1>Αλληλεπίδραση της C με την Python</h1>

## 20.2 Κλήση κώδικα C μέσα από κώδικα Python

```{.c title="ch20_blackbox.h" linenums="1"}
--8<-- "src/ch20_blackbox.h"
```

```{.c title="ch20_blackbox.c" linenums="1"}
--8<-- "src/ch20_blackbox.c"
```

```{.c title="ch20_main.c" linenums="1"}
--8<-- "src/ch20_main.c"
```

```{.py title="ch20_main_data.py" linenums="1"}
--8<-- "src/ch20_main_data.py"
```

### 20.2.1 Η βιβλιοθήκη ctypes

```{.py title="ch20_main_ctypes.py" linenums="1"}
--8<-- "src/ch20_main_ctypes.py"
```

### 20.2.2 Η βιβλιοθήκη CFFI

```{.py title="ch20_main_cffi_abi.py" linenums="1"}
--8<-- "src/ch20_main_cffi_abi.py"
```

```{.py title="ch20_main_cffi_api_builder.py" linenums="1"}
--8<-- "src/ch20_main_cffi_api_builder.py"
```

```{.py title="ch20_main_cffi_api.py" linenums="1"}
--8<-- "src/ch20_main_cffi_api.py"
```

### 20.2.3 Δημιουργία GUIs με Python και "λογικής" με C

```{.c title="ch20_gui_logic.c" linenums="1"}
--8<-- "src/ch20_gui_logic.c"
```

```{.py title="ch20_gui_cffi.py" linenums="1"}
--8<-- "src/ch20_gui_cffi.py"
```

## 20.3 Κλήση κώδικα Python από κώδικα C

```{.py title="ch20_script.py" linenums="1"}
--8<-- "src/ch20_script.py"
```

```{.c title="ch20_c_calls_python.c" linenums="1"}
--8<-- "src/ch20_c_calls_python.c"
```

## 20.4 Ασκήσεις

<!-- ***Άσκηση 1***

***Άσκηση 2*** -->

***Άσκηση 3***
```{.c title="ch20_e3.c" linenums="1"}
--8<-- "src/ch20_e3.c"
```

***Άσκηση 4***

```{.py title="ch20_e4.py" linenums="1"}
--8<-- "src/ch20_e4.py"
```
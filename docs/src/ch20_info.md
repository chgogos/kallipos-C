# Μεταγλώττιση κώδικα

Μεταγλώττιση κώδικα
```
gcc ch20_blackbox.c ch20_main.c -o ch20_main
```

Δημιουργία βιβλιοθήκης
```
gcc -shared -o ch20_blackbox.so ch20_blackbox.c -fPIC
```

```
$ source venv/bin/activate
```

```
$ python3 ch20_main_cffi_abi.py
```
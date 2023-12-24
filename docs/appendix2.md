# Παράρτημα Β

<h1>Μεταγλώττιση και εκτέλεση κώδικα C χρησιμοποιώντας το Docker</h1>

## B.1 Docker

### B.1.1 Ένα παράδειγμα μεταγλώττισης και εκτέλεσης κώδικα C με το Docker

```{.c title="appendix2/docker_example1/cprj/main.c" linenums="1"}
--8<-- "src/appendix2/docker_example1/cprj/main.c"
```

```{.docker title="appendix2/docker_example1/Dockerfile" linenums="1"}
--8<-- "src/appendix2/docker_example1/Dockerfile"
```

### B.1.2 Παράδειγμα με εγκατάσταση βιβλιοθήκης της C και προσάρτηση καταλόγου

```{.c title="appendix2/docker_example2/cprj/main.c" linenums="1"}
--8<-- "src/appendix2/docker_example2/cprj/main.c"
```

```{.mk title="appendix2/docker_example2/cprj/makefile" linenums="1"}
--8<-- "src/appendix2/docker_example2/cprj/makefile"
```

```{.docker title="appendix2/docker_example2/Dockerfile" linenums="1"}
--8<-- "src/appendix2/docker_example2/Dockerfile"
```


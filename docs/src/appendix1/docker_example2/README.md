# Execution of a C Program Using Docker Environment

Use of library GMP for calculations with big numbers

Δημιουργία του image (η εντολή δίνεται με τρέχοντα κατάλογο τον src/appendix1/docker_example2)
```
$ docker image build -t im-ubuntu-clang . 
```

<!-- https://stackoverflow.com/questions/41485217/mount-current-directory-as-a-volume-in-docker-on-windows-10 -->

Οι ακόλουθες εντολές δίνονται με τρέχοντα κατάλογο τον src/appendix1/docker_example2

Εκτέλεση του image κάνοντας mount τον κατάλογο cprj (Windows cmd) - εκτέλεση bash
```
> docker container run --rm -it -v %cd%/cprj:/cprj --name co-ubuntu-clang im-ubuntu-clang bash
```

Εκτέλεση του image κάνοντας mount τον κατάλογο cprj (Windows PowerShell) - εκτέλεση bash
```
> docker container run --rm -it -v ${PWD}/cprj:/cprj --name co-ubuntu-clang im-ubuntu-clang bash
```

Εκτέλεση του image κάνοντας mount τον κατάλογο cprj (Linux) - εκτέλεση bash
```
$ docker container run --rm -it -v $(pwd)/cprj:/cprj --name co-ubuntu-clang im-ubuntu-clang bash
```

Μεταγλώττιση και εκτέλεση του main.c 
```
# gcc -o main main.c -lgmp -Wall -Werror
# ./main 
```


Εκτέλεση του image κάνοντας mount τον κατάλογο cprj (Windows cmd) - εκτέλεση bash
```
> docker container run --rm -v %cd%/cprj:/cprj --name co-ubuntu-clang im-ubuntu-clang bash
```
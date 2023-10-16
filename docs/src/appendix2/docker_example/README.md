# Execution of a C Program Using Docker Environment

## BSD

Δημιουργία του image
```
$ docker image build -f Dockerfile_BSD -t im-freebsd . 
```

Εκτέλεση του image
```
$ docker container run --rm -it --name co-i386-ubuntu im-i386-ubuntu
```

##  i386 UBUNTU GCC & clang

Δημιουργία του image
```
$ docker image build -f Dockerfile_i386ubuntu -t im-i386-ubuntu . 
```
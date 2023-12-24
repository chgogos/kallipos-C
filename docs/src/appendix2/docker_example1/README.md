# Execution of a C Program Using Docker Environment

Δημιουργία του image
```
$ docker image build -t im-dockerhub-gcc . 
```

Εκτέλεση του image
```
$ docker container run --rm -it --name co-dockerhub-gcc im-dockerhub-gcc
```


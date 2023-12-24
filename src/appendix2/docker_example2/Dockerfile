FROM ubuntu:latest

COPY ./cprj /cprj

WORKDIR /cprj

RUN apt-get update && \
    apt-get install make && \
    apt-get -y install clang && \
    apt-get -y install libgmp-dev

RUN clang -o main main.c -lgmp -Wall -Werror
FROM gcc:13.1.0

COPY ./cprj /cprj

WORKDIR /cprj

RUN gcc -o main main.c -Wall -Werror

CMD ["./main"]
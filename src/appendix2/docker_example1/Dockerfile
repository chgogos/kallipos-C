FROM gcc:13.2.0

COPY ./cprj /cprj

WORKDIR /cprj

RUN gcc -o main main.c -Wall -Werror

CMD ["./main"]
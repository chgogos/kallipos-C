// https://programming-idioms.org/idiom/173/format-a-number-with-grouped-thousands
#define _POSIX_C_SOURCE 200809L
#include <locale.h>
#include <stdio.h>
int main() {
  setlocale(LC_ALL, "");
  printf("%'d\n", 1234567);
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {
#if defined(_WIN32)
  system("cls");
  printf("Windows\n");
#elif defined(___APPLE__)
  system("clear");
  printf("Apple OS\n");
#elif defined(__linux__)
  system("clear");
  printf("Linux OS\n");
#else
  printf("Unknown OS\n");
#endif
}

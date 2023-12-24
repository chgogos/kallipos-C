#include <stdio.h>
#include <stdlib.h>

int main(void) {
#ifdef __linux__
  printf("Hardware Information:\n");
  system("lscpu");
#elif __APPLE__
  printf("System Information:\n");
  system("system_profiler SPHardwareDataType");
#elif _WIN32
  printf("System Information:\n");
  system("systeminfo");
#else
  printf("Unsupported platform.\n");
#endif
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
#ifdef __linux__ // Linux-specific commands
  // Hardware Information using 'lshw'
  printf("Hardware Information:\n");
  system("lscpu");

  // Kernel Information using 'uname'
  printf("\nKernel Information:\n");
  system("uname -a");

  // Linux Distribution Information using 'lsb_release'
  printf("\nLinux Distribution Information:\n");
  system("lsb_release -a");

#elif __APPLE__ // macOS-specific commands
  // System Information using 'system_profiler'
  printf("System Information:\n");
  system("system_profiler SPHardwareDataType");

  // Processor Information using 'sysctl'
  printf("\nProcessor Information:\n");
  system("sysctl -n machdep.cpu.brand_string");

  // Memory Information using 'system_profiler'
  printf("\nMemory Information:\n");
  system("system_profiler SPHardwareDataType | grep Memory");

#elif _WIN32 // Windows-specific commands
  // System Information using 'systeminfo'
  printf("System Information:\n");
  system("systeminfo");

  // Processor Information using 'wmic'
  printf("\nProcessor Information:\n");
  system("wmic cpu get caption, deviceid, maxclockspeed");

  // Memory Information using 'wmic'
  printf("\nMemory Information:\n");
  system("wmic memorychip get capacity, caption, speed");

#else // Unsupported platform
  printf("Unsupported platform.\n");
#endif

  return 0;
}

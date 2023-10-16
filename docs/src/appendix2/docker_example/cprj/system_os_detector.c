#include <stdio.h>
#if __linux__
#include <sys/utsname.h>
#endif

#include <unistd.h>
int main(void) {
#if __linux__
  struct utsname uts;
  uname(&uts);
  printf("System is %s on %s hardware\n", uts.sysname, uts.machine);
  printf("OS Release is %s\n", uts.release);
  printf("OS Version is %s\n", uts.version);
#endif
}

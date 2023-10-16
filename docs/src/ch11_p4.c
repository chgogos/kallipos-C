#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int aflag = 0, bvalue = 0, option;
  double dvalue = 0.0;
  char *options = "ab:d:";
  while ((option = getopt(argc, argv, options)) != -1) {
    switch (option) {
    case 'a':
      aflag = 1;
      break;
    case 'b':
      bvalue = atoi(optarg);
      break;
    case 'd':
      dvalue = atof(optarg);
      break;
    case '?':
      printf("Error in parsing\n");
      return EXIT_FAILURE;
    }
  }
  printf("Command line arguments: a=%d  b=%d d=%lf\n", aflag, bvalue, dvalue);
  return 0;
}

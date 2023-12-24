#include <stdio.h>
#ifndef __linux__
#error "works only in linux!"
#endif

int main(void) { printf("This message should appear in Linux only"); }

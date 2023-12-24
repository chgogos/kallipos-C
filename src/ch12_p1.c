#include <stdio.h>

#include "ch12_p1.h"

int main(void) { foo(42); }

void foo(int a) { printf("foo function called with argument %d\n", a); }

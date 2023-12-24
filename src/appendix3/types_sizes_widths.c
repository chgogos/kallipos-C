#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
#if __clang__
  printf("clang %d.%d.%d detected\n", __clang_major__, __clang_minor__,
         __clang_patchlevel__);
#elif __GNUC__
  printf("GCC %d.%d.%d detected\n", __GNUC__, __GNUC_MINOR__,
         __GNUC_PATCHLEVEL__);
#elif defined(_MSC_VER)
  printf("MSVC Version=%d Full version=%d detected\n", _MSC_VER, _MSC_FULL_VER);
#endif
  printf("Platform: %d bits\n", (int)(CHAR_BIT * sizeof(void *)));
  printf("Data Type(Storage Size)\t    Value Range\n");
  printf("-------------------------------------------------------------\n");
  printf("char (%zu byte)\t\t    %d to %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
  printf("unsigned char (%zu byte)\t    0 to %u\n", sizeof(unsigned char),
         UCHAR_MAX);
  printf("signed char (%zu byte)\t    %d to %d\n", sizeof(signed char),
         SCHAR_MIN, SCHAR_MAX);
  printf("int (%zu bytes)\t\t    %d to %d\n", sizeof(int), INT_MIN, INT_MAX);
  printf("unsigned int (%zu bytes)\t    0 to %u\n", sizeof(unsigned int),
         UINT_MAX);
  printf("short (%zu bytes)\t\t    %d to %d\n", sizeof(short), SHRT_MIN,
         SHRT_MAX);
  printf("unsigned short (%zu bytes)    0 to %u\n", sizeof(unsigned short),
         USHRT_MAX);
  printf("long (%zu bytes)\t\t    %ld to %ld\n", sizeof(long), LONG_MIN,
         LONG_MAX);
  printf("unsigned long (%zu bytes)\t    0 to %lu\n", sizeof(unsigned long),
         ULONG_MAX);
  printf("long long %zu bytes\t    %lld to %lld\n", sizeof(long long),
         LLONG_MIN, LLONG_MAX);
  printf("unsigned long long (%zu bytes)0 to %llu\n",
         sizeof(unsigned long long), ULLONG_MAX);
  printf("float (%zu bytes)\t\t    %e to %e\n", sizeof(float), FLT_MIN,
         FLT_MAX);
  printf("double (%zu bytes)\t    %e to %e\n", sizeof(double), DBL_MIN,
         DBL_MAX);
  printf("long double %zu bytes\t    %Le to %Le\n", sizeof(long double),
         LDBL_MIN, LDBL_MAX);
  return 0;
}

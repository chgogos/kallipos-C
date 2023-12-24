#include <stdint.h>
#include <stdlib.h>

typedef struct {
  char name[21];
  uint32_t password;
  uint32_t salt;
} user;

uint32_t jhash(const char *str, size_t len);
uint32_t jhash_w(const char *str);

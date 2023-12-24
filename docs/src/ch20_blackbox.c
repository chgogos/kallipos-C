#include "ch20_blackbox.h"
#include <string.h>

uint32_t jhash(const char *str, size_t len) {
  uint32_t hash = 0;
  for (size_t i = 0; i < len; i++) {
    hash += str[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);
  return hash;
}

uint32_t jhash_w(const char *str) { return jhash(str, strlen(str)); }

#include "ch14_p1.h"
#include <stdio.h>
#include <string.h>

bool has_size_ok(const char *pwd) {
  int size = strlen(pwd);
  if (size >= 5 && size <= 20)
    return true;
  return false;
}

bool has_digit(const char *pwd) {
  const char *pc = pwd;
  while (*pc != '\0') {
    if (*pc >= '0' && *pc <= '9') {
      return true;
    }
    pc++;
  }
  return false;
}

bool has_lowercase_letter(const char *pwd) {
  const char *pc = pwd;
  while (*pc != '\0') {
    if (*pc >= 'a' && *pc <= 'z') {
      return true;
    }
    pc++;
  }
  return false;
}

bool has_uppercase_letter(const char *pwd) {
  const char *pc = pwd;
  while (*pc != '\0') {
    if (*pc >= 'A' && *pc <= 'Z') {
      return true;
    }
    pc++;
  }
  return false;
}

bool is_valid_password(const char *pwd) {
  if (!has_size_ok(pwd))
    return false;
  if (!has_digit(pwd))
    return false;
  if (!has_lowercase_letter(pwd))
    return false;
  if (!has_uppercase_letter(pwd))
    return false;
  return true;
}

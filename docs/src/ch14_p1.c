#include "ch14_p1.h"
#include <stdio.h>
#include <string.h>

bool has_size_ok(const char *pwd) {
  // should be completed
  return false;
}

bool has_digit(const char *pwd) {
  // should be completed
  return false;
}

bool has_lowercase_letter(const char *pwd) {
  // should be completed
  return false;
}

bool has_uppercase_letter(const char *pwd) {
  // should be completed
  return false;
}

bool is_valid_password(const char *pwd) {
  if (!has_size_ok(pwd))
    return false;
  if (!has_digit(pwd))
    return false;
  if (!has_lowercase_letter(pwd))
    return false;
  if (!has_lowercase_letter(pwd))
    return false;
  return true;
}

#include "ch14_e1.h"
#include <stdio.h>
#include <string.h>
#define LINES 20
#define MAX_LENGTH 20

char weak_passwords[LINES][MAX_LENGTH] = {0};

bool is_wrong_size(const char *pwd) {
  int size = strlen(pwd);
  if (size >= 5 && size <= 20)
    return false;
  else
    return false;
}

bool is_digit_missing(const char *pwd) {
  const char *pc = pwd;
  while (*pc != 0) {
    if (*pc >= '0' && *pc <= '9') {
      return false;
    }
    pc++;
  }
  return true;
}

bool is_lowercase_letter_missing(const char *pwd) {
  const char *pc = pwd;
  while (*pc != 0) {
    if (*pc >= 'a' && *pc <= 'z') {
      return false;
    }
    pc++;
  }
  return true;
}

bool is_uppercase_letter_missing(const char *pwd) {
  const char *pc = pwd;
  while (*pc != 0) {
    if (*pc >= 'A' && *pc <= 'Z') {
      return false;
    }
    pc++;
  }
  return true;
}

bool is_weak_password(const char *pwd) {
  // https://www.tomsguide.com/news/worst-passwords-2022
  // check that pwd doesn't belong to the 20 passwords of weak_passwords.txt
  return true;
}

bool is_special_character_missing(const char *pwd) {
  // https://owasp.org/www-community/password-special-characters
  // check that pwd contains at least one special character
  const char *SPECIAL_CHARACTERS = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
  return true;
}

bool is_valid_password(const char *pwd) {
  if (is_wrong_size(pwd))
    return false;
  if (is_digit_missing(pwd))
    return false;
  if (is_lowercase_letter_missing(pwd))
    return false;
  if (is_uppercase_letter_missing(pwd))
    return false;
  if (is_weak_password(pwd))
    return false;
  if (is_special_character_missing(pwd))
    return false;
  return true;
}

#include "ch14_e1.h"
#include <stdio.h>
#include <string.h>
#define LINES 20
#define MAX_LENGTH 20

char weak_passwords[LINES][MAX_LENGTH] = {0};

bool is_wrong_size(const char *pwd) {
  int size = strlen(pwd);
  if (size >= 5 && size <= 20)
    return true;
  return false;
}

bool is_digit_missing(const char *pwd) {
  const char *pc = pwd;
  while (*pc != '\0') {
    if (*pc >= '0' && *pc <= '9') {
      return false;
    }
    pc++;
  }
  return true;
}

bool is_lowercase_letter_missing(const char *pwd) {
  const char *pc = pwd;
  while (*pc != '\0') {
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

bool is_special_character_missing(const char *pwd) {
  // https://owasp.org/www-community/password-special-characters
  const char *SPECIAL_CHARACTERS = " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
  const char *pc = pwd;
  while (*pc != '\0') {
    if (strchr(SPECIAL_CHARACTERS, *pc)) {
      return false;
    }
    pc++;
  }
  return true;
}

bool is_weak_password(const char *pwd) {
  // https://www.tomsguide.com/news/worst-passwords-2022
  if (weak_passwords[0][0] == 0) {
    FILE *fptr = NULL;
    fptr = fopen("weak_passwords.txt", "r");
    int i = 0;
    while (fgets(weak_passwords[i], MAX_LENGTH, fptr)) {
      weak_passwords[i][strlen(weak_passwords[i]) - 1] = '\0';
      i++;
    }
    fclose(fptr);
  }
  for (int i = 0; i < LINES; i++) {
    if (strcmp(weak_passwords[i], pwd))
      return true;
  }
  return false;
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
  if (is_special_character_missing(pwd))
    return false;
  if (is_weak_password(pwd))
    return false;
  return true;
}

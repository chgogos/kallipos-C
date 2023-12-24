#include "ch20_blackbox.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 21 // μέγιστο μήκος λεκτικών
#define MAX_USERS 3   // πλήθος χρηστών
#define UB 10000 // ανώτατο όριο τυχαίων ακέραιων τιμών

int main(void) {
  char names[MAX_USERS][MAX_LENGTH] = {"daredevil", "happyhippo", "nerdalert"};
  char passwords[MAX_USERS][MAX_LENGTH] = {"12345", "password", "qwerty"};
  srand(1729); // ορίζουμε ως seed μια σταθερή τιμή για επαναληψιμότητα
  uint32_t salts[MAX_USERS] = {rand() % UB, rand() % UB, rand() % UB};
  char tmp[MAX_LENGTH];

  user users[MAX_USERS];
  for (size_t i = 0; i < MAX_USERS; ++i) {
    strcpy(users[i].name, names[i]);
    snprintf(tmp, MAX_LENGTH, "%u", salts[i]);
    users[i].password = jhash_w(strcat(passwords[i], tmp));
    users[i].salt = salts[i];
    printf("user = %s, password = %u salt = %u\n", users[i].name,
           users[i].password, users[i].salt);
  }

  char a_user_name[MAX_LENGTH];
  char pwd[MAX_LENGTH];
  printf("Enter user name: ");
  scanf("%20s", a_user_name);
  printf("Enter the password of user %s: ", a_user_name);
  scanf("%20s", pwd);

  bool login = false;
  for (size_t i = 0; i < MAX_USERS; ++i) {
    if (strcmp(users[i].name, a_user_name) != 0)
      continue;
    snprintf(tmp, MAX_LENGTH, "%u", users[i].salt);
    if (users[i].password == jhash_w(strcat(pwd, tmp))) {
      login = true;
      break;
    }
  }
  printf("LOGIN %s\n", login ? "SUCCESS" : "FAIL");
}

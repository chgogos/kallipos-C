#include <stdio.h>
#include <string.h>

int main() {
  char msg[80] = "I think there's a world market for about 5 computers.";
  // memcpy(msg, msg + 18, 5); // μη καθορισμένη συμπεριφορά
  memmove(msg, msg + 18, 5);
  printf("%s\n", msg);
  return 0;
}

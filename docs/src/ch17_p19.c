#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void) {
  time_t t1 = time(NULL); // τρέχουσα χρονική στιγμή
  char *s_t1 = ctime(&t1);
  printf("Time1: %s", s_t1);
  sleep(2); // παύση εκτέλεσης για 2 δευτερόλεπτα
  time_t t2 = time(NULL); // τρέχουσα χρονική στιγμή
  char *s_t2 = ctime(&t2);
  printf("Time2: %s", s_t2);
  int time_elapsed = difftime(t2, t1);
  printf("Time gap between prints: %d seconds\n", time_elapsed);
  return 0;
}

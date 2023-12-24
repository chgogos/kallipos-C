#include <stdio.h>
#include <time.h>

int main(void) {
  time_t now = time(NULL);
  struct tm *t = gmtime(&now);
  printf("UTC time=%s", asctime(t));
  // 1 ημέρα + 10 ώρες μετά
  t->tm_mday += 1;
  t->tm_hour = t->tm_hour + 10;
  // μετατροπή σε time_t για κανονικοποίηση ημερομηνίας
  time_t future_time = timegm(t);
  t = gmtime(&future_time);
  char s[100];
  strftime(s, sizeof s, "%A %c", t);
  printf("UTC time(+1day, 10hours)=%s\n", s);
  return 0;
}

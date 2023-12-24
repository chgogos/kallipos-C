#include <stdio.h>
#include <time.h>

int main(void) {
  struct tm date1 = {0}, date2 = {0};
  time_t time1, time2;
  double seconds;
  int year, month, day;

  // Εισαγωγή της πρώτης ημερομηνίας
  printf("Enter the first date (YYYY MM DD): ");
  scanf("%d %d %d", &year, &month, &day);
  date1.tm_year = year - 1900; // Το έτος από το 1900
  date1.tm_mon = month - 1; // Ο μήνας από 0 (Ιανουάριος = 0)
  date1.tm_mday = day;

  // Εισαγωγή της δεύτερης ημερομηνίας
  printf("Enter the second date (YYYY MM DD): ");
  scanf("%d %d %d", &year, &month, &day);
  date2.tm_year = year - 1900;
  date2.tm_mon = month - 1;
  date2.tm_mday = day;

  // Μετατροπή σε time_t
  time1 = mktime(&date1);
  time2 = mktime(&date2);

  // Υπολογισμός διαφοράς σε δευτερόλεπτα και μετατροπή σε ημέρες
  seconds = difftime(time2, time1);
  printf("Dates difference is %.0f days.\n", seconds / (60 * 60 * 24));

  return 0;
}

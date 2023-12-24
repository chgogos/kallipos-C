#include <stdio.h>
#include <string.h>

int main(void) {
  char info[100];
  int day, month, year;
  strcpy(info, "Day:9 Month:10 Year:2017");
  sscanf(info, "Day:%d Month:%d Year:%d", &day, &month, &year);
  printf("The final draft of C17 standard was published in: %d/%d/%d\n", day,
         month, year);
  return 0;
}

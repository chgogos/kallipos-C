#include <stdio.h>

typedef struct {
  int hour;
  int minute;
  int second;
} time;

time read_time(void) {
  time t;
  printf("Input hours, minutes, seconds: ");
  scanf("%d%d%d", &t.hour, &t.minute, &t.second);
  return t;
}

void print_time(time t, int flag24) {
    int hour = (flag24 == 1 || t.hour < 12) ? t.hour : t.hour - 12;
    printf("%d:%d:%d\n", hour, t.minute, t.second);
}

int main(void) {
  time a_time = read_time();
  print_time(a_time, 0);
  print_time(a_time, 1);
  return 0;
}

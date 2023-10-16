#include <stdio.h>

typedef struct {
  int hour;
  int minute;
  int second;
} time;

time read_time() {
  time t;
  printf("Input hours, minutes, seconds: ");
  scanf("%d%d%d", &t.hour, &t.minute, &t.second);
  return t;
}

void print_time(time t, int flag24) {
  if (flag24 == 1) {
    printf("%d:%d:%d\n", t.hour, t.minute, t.second);
  } else {
    printf("%d:%d:%d\n", t.hour - 12, t.minute, t.second);
  }
}

time advance_time(time t) {
  t.second++;
  if (t.second == 60) {
    t.second = 0;
    t.minute++;
    if (t.minute == 60) {
      t.minute = 0;
      t.hour++;
      if (t.hour == 24) {
        t.hour = 0;
      }
    }
  }
  return t;
}

int main(void) {
  time a_time, a_time_plus;
  a_time = read_time();
  print_time(a_time, 1);
  a_time_plus = advance_time(a_time);
  print_time(a_time_plus, 1);
  return 0;
}
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

int time2seconds(time t) {
  return t.hour * 60 * 60 + t.minute * 60 + t.second;
}

int compare_time(time t1, time t2) {
  int t1seconds = time2seconds(t1);
  int t2seconds = time2seconds(t2);
  if (t1seconds > t2seconds) {
    return 1;
  } else if (t1seconds < t2seconds) {
    return -1;
  } else {
    return 0;
  }
}

int main(void) {
  time time1, time2;
  int t;
  time1 = read_time();
  time2 = read_time();
  t = compare_time(time1, time2);
  if (t == 1) {
    printf("The first time that was given is greater\n");
  } else if (t == -1) {
    printf("The second time that was given is greater\n");
  } else {
    printf("Both times are equal\n");
  }
  return 0;
}

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

bool isPaused = false;
void togglePause(void) { isPaused = !isPaused; }

int main(int argc, char *argv[]) {
  if (argc > 2) {
    printf("Usage for 1 minute timer: %s\n", argv[0]);
    printf("Usage for <minutes> timer: %s <minutes>\n", argv[0]);
    return 1;
  }
  int duration = 60;
  if (argc == 2) {
    duration = atoi(argv[1]) * 60;
  }

  initscr();     // αρχικοποίηση της οθόνης
  start_color(); // έναρξη λειτουργικότητας χρωμάτων
  cbreak();      // αρχικοποίηση της οθόνης
  noecho(); // απόκρυψη της εισόδου που πληκτρολογεί ο χρήστης
  nodelay(stdscr, TRUE); // κάνε τη getch() non-blocking

  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);

  int win_height = 4, win_width = 50;
  int starty = (LINES - win_height) / 2; // κεντράρισμα κατακόρυφα
  int startx = (COLS - win_width) / 2; // κεντράρισμα οριζόντια
  WINDOW *timer_win = newwin(win_height, win_width, starty, startx);
  box(timer_win, 0, 0); // σχεδίαση ενός πλαισίου γύρω από το παράθυρο
  time_t startTime = time(NULL); // η ώρα έναρξης του μετρητή
  int elapsed = 0;
  printw("\nPress 'p' to pause/resume or 'q' to exit the timer.");
  refresh();
  while (elapsed < duration) {
    int ch = getch();
    if (ch == 'p' || ch == 'P') { // p για παύση/επανεκκίνηση
      togglePause();
    } else if (ch == 'q' || ch == 'Q') { // q για έξοδο
      break;
    }
    if (!isPaused) {
      wclear(timer_win);
      box(timer_win, 0, 0); // ξανασχεδίασε το πλαίσιο
      int remaining = duration - elapsed;
      int color_pair =
          remaining <= 30 ? 2 : 1; // αλλαγή χρώματος σε κόκκινο για τα
                                   // τελευταία 30 δευτερόλεπτα
      wattron(timer_win, COLOR_PAIR(color_pair));
      mvwprintw(timer_win, 1, 1, "Timer: %d out of %d seconds remaining.",
                duration - elapsed, duration);
      wattroff(timer_win, COLOR_PAIR(color_pair));
      wrefresh(timer_win);
      napms(100); // περίμενε 1 δευτερόλεπτο
      elapsed = time(NULL) - startTime;
    } else {
      wrefresh(timer_win);
      mvwprintw(timer_win, 2, 1, "Paused - Press 'p' to resume.");
      napms(100); // Περίμενε 0.1 δευτερόλεπτα
    }
  }
  endwin();
  return 0;
}

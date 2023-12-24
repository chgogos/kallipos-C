#include <ncurses.h>

#define MENU_ITEMS 3
#define WIDTH 30
#define HEIGHT 10

void print_menu(WINDOW *menu_win, int highlight, char *choices[]) {
  int x = 2, y = 2;
  box(menu_win, 0, 0);
  for (int i = 0; i < MENU_ITEMS; ++i) {
    if (highlight == i + 1) { // Τόνισε την επιλογή
      wattron(menu_win, A_REVERSE);
      mvwprintw(menu_win, y, x, "%s", choices[i]);
      wattroff(menu_win, A_REVERSE);
    } else
      mvwprintw(menu_win, y, x, "%s", choices[i]);
    ++y;
  }
  wrefresh(menu_win);
}

int main(void) {
  char *choices[] = {
      "Choice 1",
      "Choice 2",
      "Exit",
  };
  int highlight = 1;
  int choice = 0;
  int c;

  initscr();
  clear();
  noecho();
  cbreak();

  int startx = (80 - WIDTH) / 2;
  int starty = (24 - HEIGHT) / 2;

  WINDOW *menu_win = newwin(HEIGHT, WIDTH, starty, startx);
  keypad(menu_win, TRUE); // Ενεργοποίησε τα βελάκια
  mvprintw(0, 0, "Use up and down arrows to move, enter to select a choice");
  refresh();
  while (1) {
    print_menu(menu_win, highlight, choices);
    c = wgetch(menu_win); // Περίμενε για είσοδο από το χρήστη
    switch (c) {
    case KEY_UP:
      if (highlight == 1)
        highlight = MENU_ITEMS;
      else
        --highlight;
      break;
    case KEY_DOWN:
      if (highlight == MENU_ITEMS)
        highlight = 1;
      else
        ++highlight;
      break;
    case 10:
      choice = highlight;
      mvprintw(1, 0, "You selected %s",
               choices[highlight - 1]); // Εμφάνισε την επιλογή
      refresh();
      break;
    default:
      refresh();
      break;
    }
    if (choice == 3)
      break;
  }
  clrtoeol();
  refresh();
  endwin();
  return 0;
}

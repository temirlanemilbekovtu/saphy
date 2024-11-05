#include <ncurses.h>

int main() {
    initscr();
    raw();
    nonl();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    endwin();

    return 0;
}

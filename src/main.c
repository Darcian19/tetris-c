#include <ncurses.h>

int main(void) {
    initscr();
    printw("TETRIS - press q to quit");
    refresh();

    int ch;
    while ((ch = getch()) != 'q') {
    }

    endwin();
    return 0;
}

#include <ncurses.h>
#include "tetris.h"

int main(void) {
    Board board;
    board_init(&board);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    board.cells[19][4]=1; 
    refresh();

    int ch;
    while ((ch = getch()) != 'q') 
    { 
        clear(); 
        mvprintw( 0,4, "TETRIS"); 
        board_render(&board); 
        refresh(); 
    }
    endwin();
    return 0;
}

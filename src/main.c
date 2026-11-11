#include <ncurses.h>
#include "tetris.h"

int main(void) {
    Board board;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    board_init(&board);
        

    int ch;
    while ((ch = getch()) != 'q'  &&  ch!='Q') 
    { 
        clear(); 
        mvprintw( 0,4, "TETRIS"); 
        board_render(&board);
        
        switch (ch) 
        {
           case 'a':
           case 'A': 
              mvprintw(23,4,"LEFT"); 
              break; 
           case 's':
           case 'S': 
              mvprintw(23,4,"DOWN"); 
              break; 
           case 'd': 
           case 'D': 
              mvprintw(23,4,"RIGHT"); 
              break; 
           default: 
              mvprintw(23,4, "UNKNOWN KEY"); 
              break;
         }  
        refresh(); 
    }
    endwin();
    return 0;
}


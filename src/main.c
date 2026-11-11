#include <ncurses.h>
#include "tetris.h"

int main(void) {
    Board board;
    Piece piece;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    board_init(&board);
    piece_spawn(&piece);
        

    int ch;
    while ((ch = getch()) != 'q'  &&  ch!='Q') 
    { 
        
        switch (ch) 
        {
           case 'a':
           case 'A': 
              piece_move(&board, &piece, -1,0); 
              break; 
           case 's':
           case 'S': 
              piece_move(&board, &piece, 0,1);
              break;
	  case 'd':
          case 'D': 
              piece_move(&board, &piece, 1,0);
              break; 
         }  
	clear();
	mvprintw(0,4,"TETRIS");
	board_render(&board); 
	piece_render(&piece); 
        refresh(); 
    }
    endwin();
    return 0;
}


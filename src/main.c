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
        
    timeout(750);

    int ch;
    while ((ch = getch()) != 'q'  &&  ch!='Q') 
    { 
        if (ch ==ERR)
	{
		if(piece_can_move(&board,&piece,0,1))
		{
			piece_move(&board , &piece, 0,1);
		}
		else 
		{
			piece_lock(&board , &piece);
			board_clear_lines(&board);
			piece_spawn(&piece);
			if (!piece_can_move(&board,&piece,0,0))
			{
				mvprintw(0,20,"GAME OVER");
				refresh();
				getch();
				break;
			}
		}
	}
	else
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
	  	case 'w': 
	  	case 'W': 
	  	    piece_rotate(&board, &piece);
	  	    break;  
         	}
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


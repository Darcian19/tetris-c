#include <ncurses.h>
#include "tetris.h"

int main(void) {
    Board board;
    Piece piece;
    GameState state; 

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    board_init(&board);
    piece_spawn(&piece);
    game_init(&state);
        
    timeout(game_get_delay(&state));

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
			int cleared = board_clear_lines(&board); 
			game_update_score(&state,cleared);


			piece_spawn(&piece);
			if (!piece_can_move(&board,&piece,0,0))
			{
				clear(); 
				mvprintw(0,20,"GAME OVER");
				mvprintw(12,4,"SCORE: %d", state.score);
				mvprintw(13,4,"PRESS r TO RESTART");
				refresh();
				
				int restart_key = getch();
				if (restart_key == 'r' || restart_key=='R')
				{
					board_init(&board);
					piece_spawn(&piece);
					game_init(&state);
					timeout(game_get_delay(&state));
					continue;
				}
				break; 
			}
			timeout(game_get_delay(&state));
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
		case 'r':
		case 'R':
		    board_init(&board);
                    piece_spawn(&piece);
                    game_init(&state);
                    timeout(game_get_delay(&state));
                    break;
         	}
	} 
	clear();
	mvprintw(0,4,"TETRIS");
	mvprintw(1,4,"SCORE :%d", state.score);
	mvprintw(2,4,"LEVEL :%d", state.level);
	mvprintw(3,4,"LINES: %d", state.lines);
	board_render(&board); 
	piece_render(&piece); 
        refresh(); 
    }
    endwin();
    return 0;
}


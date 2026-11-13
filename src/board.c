#include "tetris.h"
#include <ncurses.h>
void board_init(Board *board) {
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            board->cells[y][x] = 0;
        }
    }
}
void board_render(const Board *board) 
{
    for (int y=0; y<BOARD_HEIGHT; y++) 
    {
        for (int x=0; x<BOARD_WIDTH;x++) 
        { 
              if (board->cells[y][x]==0) 
              {
                  mvprintw(y+2,x*2+4,"  "); 
              } 
              else 
              { 
                  mvprintw(y+2,x*2+4,"[]"); 
              }
         } 
     }
}
int board_clear_lines(Board *board) 
{
	int cleared =0; 
	for (int y=BOARD_HEIGHT-1;y>=0;y--) 
	{
		int full=1;
		for (int x=0;x<BOARD_WIDTH;x++)
		{
 
			if(board->cells[y][x]==0)
			{
				full =0; 
				break;
			}
		}

	if (full) 
	{
		cleared++; 
		for (int row =y;row>0;row--) 
		{
			for (int x =0;x<BOARD_WIDTH;x++)
			{
				board->cells[row][x]=board->cells[row-1][x];
			}
		}
		for (int x=0;x<BOARD_WIDTH;x++) 
		{
			board->cells[0][x]=0;
		}
		y++;
	}
	}
	return cleared;
}	

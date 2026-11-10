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


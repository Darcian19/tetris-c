#include <ncurses.h> 

int main(void) 
{
      initscr(); 
      cbreak();
      noecho();
      keypad(stdscr, TRUE); 

      printw("TETRIS\n"); 
      printw("Press q to quit\n"); 
      refresh(); 

      int ch; 
      while ((ch = getch())!='q') 
      {
       }

      endwin();
      return 0;
}


#ifndef TETRIS_H
#define TETRIS_H

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

typedef struct {
    int cells[BOARD_HEIGHT][BOARD_WIDTH];
} Board;

void board_init(Board *board);
void board_render(const Board *board); 
int board_clear_lines(Board *board); 
typedef struct{
	int type; 
	int rotation; 
	int x; 
	int y; 
} Piece; 

void piece_spawn(Piece *piece); 
int piece_can_move(const Board *board, const Piece *piece, int dx, int dy); 
void piece_move(Board *board, Piece *piece, int dx, int dy);
void piece_render(const Piece *piece);

void piece_rotate(Board *board, Piece *piece);
void piece_lock(Board *board,const Piece *piece);    

#endif

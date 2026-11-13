#include <ncurses.h> 
#include "tetris.h" 

static const int SHAPES[7][4][4][4] = {
    // I
    {
        {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
        {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
        {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
        {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}}
    },
    // O
    {
        {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
        {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
        {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
        {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}}
    },
    // T
    {
        {{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
        {{0,1,0,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
        {{0,0,0,0},{1,1,1,0},{0,1,0,0},{0,0,0,0}},
        {{0,1,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}}
    },
    // S
    {
        {{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
        {{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
        {{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
        {{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}}
    },
    // Z
    {
        {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
        {{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}},
        {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
        {{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}}
    },
    // J
    {
        {{1,0,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
        {{0,1,1,0},{0,1,0,0},{0,1,0,0},{0,0,0,0}},
        {{0,0,0,0},{1,1,1,0},{0,0,1,0},{0,0,0,0}},
        {{1,0,0,0},{1,0,0,0},{1,1,0,0},{0,0,0,0}}
    },
    // L
    {
        {{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
        {{1,0,0,0},{1,0,0,0},{1,1,0,0},{0,0,0,0}},
        {{0,0,0,0},{1,1,1,0},{1,0,0,0},{0,0,0,0}},
        {{1,1,0,0},{0,1,0,0},{0,1,0,0},{0,0,0,0}}
    }
};

void piece_spawn(Piece *piece){
	piece->type = 0 ;
	piece->rotation =0; 
	piece->x=3;
	piece->y = 0; 
}

int piece_can_move(const Board *board, const Piece *piece, int dx, int dy){
	for (int py=0;py<4;py++) {
		for (int px =0; px<4;px++){
			if (SHAPES[piece->type][piece->rotation][py][px]==0){
				continue;
				}
			int board_x = piece -> x + px + dx; 
			int board_y = piece -> y + py + dy; 
			if (board_x < 0 || board_x >= BOARD_WIDTH) {
				return 0; 
			}
			if (board_y >=BOARD_HEIGHT){
				return 0; 
			}
 			if (board_y >=0  && board->cells[board_y][board_x] !=0) {
				return 0;
			}
		}
	}
	return 1; 
}

void piece_move(Board *board, Piece *piece, int dx, int dy){ 
	if (piece_can_move(board, piece,dx, dy)){
		piece->x +=dx; 
		piece->y +=dy; 
	}
}

void piece_render(const Piece *piece) {
    for (int py = 0; py < 4; py++) {
        for (int px = 0; px < 4; px++) {
            if (SHAPES[piece->type][piece->rotation][py][px] == 0) {
                continue;
            }

            int board_x = piece->x + px;
            int board_y = piece->y + py;

            if (board_x < 0 || board_x >= BOARD_WIDTH) {
                continue;
            }

            if (board_y < 0 || board_y >= BOARD_HEIGHT) {
                continue;
            }

            mvprintw(board_y + 2, board_x * 2 + 4, "[]");
        }
    }
}

void piece_rotate (Board *board, Piece *piece) {
	int old_rotation = piece->rotation; 
	piece->rotation = (piece->rotation +1) %4; 
	if (!piece_can_move(board, piece, 0, 0)){
		piece->rotation = old_rotation;
	}
}
void piece_lock(Board *board, const Piece *piece) 
{
	for (int py=0;py<4;py++) 
	{
		for (int px=0;px<4;px++) 
		{
			if (SHAPES[piece->type][piece->rotation][py][px]==0)
			{
				continue;
			}
			int board_x = piece->x +px;
			int board_y = piece->y + py;
			if (board_x>=0 && board_x< BOARD_WIDTH && board_y >=0 && board_y <BOARD_HEIGHT)
			{
				board->cells[board_y][board_x]=1;
			}
		}
	}
} 

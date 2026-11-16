#include "tetris.h"

void game_init(GameState *state)
{
	state->score =0;
	state->level =1;
	state->lines =0;
}

void game_update_score(GameState *state, int cleared)
{
	int points =0; 
	switch (cleared) 
	{
		case 1: points =100; break;
		case 2: points = 300;break;
		case 3: points = 500; break;
		case 4: points =800; break; 
	}
	state->score+=points *state->level;
	state->lines +=cleared; 
	state->level =1 + state->lines/10; 
}

int game_get_delay (const GameState *state)
{
	int delay =500 - (state->level -1)*40; 
	if (delay <100)
	{
		delay =100; 
	}
	return delay; 
} 


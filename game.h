#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAP_WIDTH 32
#define MAP_HEIGHT 32

#define CELL_GREEN  "\xF0\x9F\x9F\xA9"
#define CELL_BROWN  "\xF0\x9F\x9F\xAB"

#define UPDATE_TIME 9200

void update_cells(int* newMap);
int update_map_state();
void start();
void clear_console();
int update();

#endif // game.h
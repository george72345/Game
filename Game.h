#ifndef GAME_H
#define GAME_H

#include "Player.h"//include player structure definition

//define constants
#define TOTAL_GAME_TIME 300 // 5 minute time limit

//function prototypes
void startGame(Player *player);
void endGame(Player *player);

#endif
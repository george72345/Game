#ifndef MAP_H
#define MAP_H


//define constants
#include "Player.h"
#include "Constants.h"
#include <stdbool.h>

//define structures
typedef enum{
    SQUARE_EMPTY,
    SQUARE_OBSTACLE,
    SQUARE_ORE
} SquareType;


typedef struct {
    SquareType type;
    int oreType;
    bool mined;
} MapSquare;

//ore probability function
int generateRandomOreType();

//function prototypes
void generateMap(MapSquare map[MAP_SIZE][MAP_SIZE], Player *player);
void displayMap(MapSquare map[MAP_SIZE][MAP_SIZE], Player *player);





#endif
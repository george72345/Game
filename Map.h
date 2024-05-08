#ifndef MAP_H
#define MAP_H


//define constants

#include "Constants.h"

//define structures
typedef enum{
    SQUARE_EMPTY,
    SQUARE_OBSTACLE,
    SQUARE_ORE
} SquareType;


typedef struct {
    SquareType type;
    int oreType;
} MapSquare;

//ore probability function
int generateRandomOreType();

//function prototypes
void generateMap(MapSquare map[MAP_SIZE][MAP_SIZE]);
void displayMap(MapSquare map[MAP_SIZE][MAP_SIZE]);



#endif
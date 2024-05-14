#ifndef MINING_H
#define MINING_H
#define EMPTY 0

#include "Player.h" //include player structure definition

//define constants
#define MAP_SIZE 12

//define structures
typedef struct {
    int x;
    int y;
} Coordinates;

typedef struct {
    char type[20];
    int value;
    int rarity;
} Ore;

typedef struct {
    Ore ores[3];
    Coordinates obstacles[3];
} MapSquare;

//function prototypes
void mineCurrentSquare(Player *player, MapSquare map[][MAP_SIZE]);

#endif
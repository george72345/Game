#ifndef PLAYER_H
#define PLAYER_H

#define MAP_SIZE 12
#define VISIBILITY_RANGE 2

//define structures
typedef struct {
    int x; //players x-coordinate
    int y; //players y-coordinate
    int visibility[MAP_SIZE][MAP_SIZE];
} Player;

void movePlayer(Player *player, char direction);

#endif
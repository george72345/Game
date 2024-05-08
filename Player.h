#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"//Include inventory structure definition

//define structures
typedef struct {
    char name[50];
    int coins;
    int posX;
    int posY;
    InventoryItem inventory[MAX_INVENTORY_SIZE];
} Player;

#endif
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Player.h" //Inlcude player structure definition

//define constants
#define MAX_INVENTORY_SIZE 6

//define structures
typedef struct{
    char name[20];
    int quantity;
} InventoryItem;

//function prototypes
void initializeInventory(Player *player);
void addToInventory(Player *player, InventoryItem item);
void useItem(Player *player, InventoryItem item);

#endif
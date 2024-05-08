#ifndef SHOP_H
#define SHOP_H

#include "Player.h" //Include player structure definition

//define structures
typedef struct {
    char name[20];
    int price;
} ShopItem;

//function prototypes
void initializeShop(ShopItem, shop[]);
void buyItem(Player *player, ShopItem item);

#endif
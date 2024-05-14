#include <stdio.h>
#include "Inventory.h"

//function to initialize the player's inventory
void initializeInventory(Inventory *inventory) {
    //set the number of items in the inventory to zero
    inventory->numItems = 0;
}

//function to add an item to the player's inventory
void addItemToInventory(Inventory *inventory, ItemType type, int quantity) {
    //check if the inventory is full
    if (inventory->numItems >= MAX_INVENTORY_SIZE) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    //add the item to the inventory
    inventory->items[inventory->numItems].type = type;
    inventory->items[inventory->numItems].quantity = quantity;
    inventory->numItems++;
}

//function to display the player's inventory
void displayInventory(Inventory *inventory) {
    printf("Player's Inventory:\n");
    if (inventory->numItems == 0) {
        printf("Inventory is empty.\n");
    } else {
        for (int i = 0; i < inventory->numItems; i++) {
            printf("- %d %s\n", inventory->items[i].quantity, itemName(inventory->items[i].type));
        }
    }
}

//function to get the name of an item based on its type
const char *itemName(ItemType type) {
    switch (type) {
        case ITEM_COPPER:
            return "Copper";
        case ITEM_GOLD:
            return "Gold";
        case ITEM_DIAMOND:
            return "Diamond";
        case ITEM_METEORITE:
            return "Meteorite";
        default:
            return "Unknown";
    }
}

#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_INVENTORY_SIZE 10

//fefine the types of items that can be collected
typedef enum {
    ITEM_COPPER,
    ITEM_GOLD,
    ITEM_DIAMOND,
    ITEM_METEORITE,
    NUM_ITEM_TYPES
} ItemType;

//function declaration for itemName
const char* itemName(ItemType type);

//define the structure for an item in the inventory
typedef struct {
    ItemType type; //type of the item
    int quantity;  //quantity of the item
} InventoryItem;

//define the structure for the player's inventory
typedef struct {
    InventoryItem items[MAX_INVENTORY_SIZE]; //array to hold the inventory items
    int numItems; //number of items currently in the inventory
} Inventory;

//function to initialize the player's inventory
void initializeInventory(Inventory *inventory);

//function to add an item to the player's inventory
void addItemToInventory(Inventory *inventory, ItemType type, int quantity);

//function to display the player's inventory
void displayInventory(Inventory *inventory);

#endif

#include <stdio.h>
#include "Map.h"
#include "Player.h" //include the Player header file
#include "Inventory.h"


#define MAX_RULES_LENGTH 1000

//function to display the rules from a text file
void displayRules() {
    //open the text file
    FILE *file = fopen("Rules.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open Rules.txt\n");
        return;
    }

    //read the content of the file
    char rules[MAX_RULES_LENGTH];
    while (fgets(rules, MAX_RULES_LENGTH, file) != NULL) {
        printf("%s", rules);
    }

    //close the file
    fclose(file);
}

int main() {

    //define the map and player
    MapSquare map[MAP_SIZE][MAP_SIZE];
    Player player;

    //initialize the player's position
    player.x = 0;
    player.y = 0;

    Inventory playerInventory;
    initializeInventory(&playerInventory);

    displayRules();
    printf("\n");
    //generate the map
    generateMap(map, &player);

    //display the initial map with the player's position
    displayMap(map, &player); //pass a pointer to the player

    //game loop
    char direction;
    while (1) {
        //get player input for movement direction
        printf("Enter movement direction (w/a/s/d to move, i to display inventory and q to quit): ");
        scanf(" %c", &direction);

        //check if the user wants to quit the game
        if (direction == 'q') {
            printf("Thanks for playing. Goodbye!\n");
            break; //exit the loop
        }

        if (direction == 'i'){
            displayInventory(&playerInventory);
            continue;
        }

        //move the player accordingly
        movePlayer(&player, direction);

        //display the updated map with the player's new position
        displayMap(map, &player);
    }

    return 0;
}

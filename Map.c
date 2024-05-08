#include "Map.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//implement the generate random ore function
int generateRandomOreType(){
    //generate a random number between 0 and 99
    int randNum = rand() % 100;

    //define the probabilities for each ore type
    int copperProb = 30;
    int goldProb = 25;
    int diamondProb = 15;
    int meteoriteProb = 5;
    int emptyProb = 25;

    if (randNum < copperProb){
        return COPPER;
    }else if (randNum < copperProb + goldProb){
        return GOLD;
    }else if (randNum < copperProb + goldProb + diamondProb){
        return DIAMOND;
    }else if (randNum < copperProb + goldProb + diamondProb + meteoriteProb){
        return METEORITE;
    }else{
        return EMPTY;
    }
}

//implement the generate map function
void generateMap(MapSquare map[MAP_SIZE][MAP_SIZE]){
    // Initialize the map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j].type = SQUARE_EMPTY;
            map[i][j].oreType = EMPTY;
        }
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Place at least three obstacles randomly
    int numObstaclesPlaced = 0;
    while (numObstaclesPlaced < 3) {
        int randX = rand() % MAP_SIZE; // Random x-coordinate
        int randY = rand() % MAP_SIZE; // Random y-coordinate

        // Check if the chosen square is empty
        if (map[randX][randY].type == SQUARE_EMPTY) {
            // Place an obstacle
            map[randX][randY].type = SQUARE_OBSTACLE;
            numObstaclesPlaced++;
        }
    }
    for (int i = 0; i < MAP_SIZE; i++){
        for (int j = 0; j < MAP_SIZE; j++){
            map[i][j].oreType = generateRandomOreType();

            if (map[i][j].oreType == EMPTY){
                map[i][j].type = SQUARE_EMPTY;
            }else{
                map[i][j].type = SQUARE_ORE;
            }
        }
    }
}

// Function to display the game map
void displayMap(MapSquare map[MAP_SIZE][MAP_SIZE]) {
    // Iterate over each square in the map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            // Check the type of the current square
            switch (map[i][j].type) {
                case SQUARE_EMPTY:
                    printf(" "); // Display an empty square
                    break;
                case SQUARE_OBSTACLE:
                    printf("#"); // Display an obstacle
                    break;
                case SQUARE_ORE:
                    // Display the ore type based on the ore type
                    switch (map[i][j].oreType) {
                        case COPPER:
                            printf("C"); // Display copper ore
                            break;
                        case GOLD:
                            printf("G"); // Display gold ore
                            break;
                        case DIAMOND:
                            printf("D"); // Display diamond ore
                            break;
                        case METEORITE:
                            printf("M"); // Display meteorite ore
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        printf("\n"); // Move to the next line after printing each row
    }
}
#include "Map.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Player.h"

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
void generateMap(MapSquare map[MAP_SIZE][MAP_SIZE], Player *player) {
    //initialize the map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j].type = SQUARE_EMPTY;
            map[i][j].oreType = EMPTY;
        }
    }

    srand(time(NULL));

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j].oreType = generateRandomOreType();
            if (map[i][j].oreType != EMPTY) {
                map[i][j].type = SQUARE_ORE;
            }
        }
    }

    //place at least three obstacles randomly
    int numObstaclesPlaced = 0;
    while (numObstaclesPlaced < 10) {
        int randX = rand() % MAP_SIZE;
        int randY = rand() % MAP_SIZE;

        //check if the chosen square is empty
        if (map[randX][randY].type == SQUARE_EMPTY) {
            //place an obstacle
            map[randX][randY].type = SQUARE_OBSTACLE;
            numObstaclesPlaced++;
        }
    }

    //update visibility array based on the player's initial position
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            //calculate Manhattan distance between player's position and square position
            int distance = abs(player->x - i) + abs(player->y - j);
            //if distance is within visibility range, set visibility to true
            player->visibility[i][j] = (distance <= VISIBILITY_RANGE);
        }
    }
}


void displayMap(MapSquare map[MAP_SIZE][MAP_SIZE], Player *player) {
    //iterate over each square in the map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            //check if the square is within the player's visibility area
            if (player->visibility[i][j]) {
                //check if the square contains the player
                if (player->x == i && player->y == j) {
                    printf("* "); //display the player's position
                } else {
                    //check the type of the current square
                    switch (map[i][j].type) {
                        case SQUARE_EMPTY:
                            printf("  "); //display an empty square
                            break;
                        case SQUARE_OBSTACLE:
                            printf("# "); // display an obstacle
                            break;
                        case SQUARE_ORE:
                            //display the ore type based on the ore type
                            switch (map[i][j].oreType) {
                                case COPPER:
                                    printf("C "); //display copper ore
                                    break;
                                case GOLD:
                                    printf("G "); //display gold ore
                                    break;
                                case DIAMOND:
                                    printf("D "); //display diamond ore
                                    break;
                                case METEORITE:
                                    printf("M "); //display meteorite ore
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                }
            } else {
                printf("? "); //display a hidden square
            }
        }
        printf("\n"); //move to the next line after printing each row
    }
}








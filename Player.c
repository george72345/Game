#include <stdio.h>
#include <stdlib.h>
#include "Player.h"



void movePlayer(Player *player, char direction) {
    // Update player's position based on the direction
    switch (direction) {
        case 'w':
            if (player->x > 0) {
                player->x--; // Move up
            }
            break;
        case 'a':
            if (player->y > 0) {
                player->y--; // Move left
            }
            break;
        case 's':
            if (player->x < MAP_SIZE - 1) {
                player->x++; // Move down
            }
            break;
        case 'd':
            if (player->y < MAP_SIZE - 1) {
                player->y++; // Move right
            }
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }

    // Update visibility array based on the player's new position
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            // Calculate Manhattan distance between player's position and square position
            int distance = abs(player->x - i) + abs(player->y - j);
            // If distance is within visibility range, set visibility to true
            player->visibility[i][j] = (distance <= VISIBILITY_RANGE);
        }
    }
}


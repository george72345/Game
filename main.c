#include "Map.h"

int main() {
    // Define the map array
    MapSquare map[MAP_SIZE][MAP_SIZE];

    // Generate the map
    generateMap(map);

    // Display the map
    displayMap(map);

    return 0;
}
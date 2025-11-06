#include <iostream>
#include <cassert>
#include <vector>

/*
Problem 15: Lattice paths
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

a diagram of 6 2 by 2 grids showing all the routes to the bottom right corner
How many such routes are there through a given gridSize?

*/

unsigned long long latticePaths(int gridSize) {
    unsigned long long answer = 0;
    std::vector<std::vector<unsigned long long>> paths(gridSize + 1, std::vector<unsigned long long>(gridSize + 1, 0));

    for (int i = 0;i <= gridSize; i++) {
        paths[i][0] = 1;
        paths[0][i] = 1;
    }

    for (int i = 1; i <= gridSize; i++) {
        for (int j = 1; j <= gridSize; j++) {
            paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
        }
    }

    return paths[gridSize][gridSize];
}



int main() {

    assert(latticePaths(2) == 6);
    assert(latticePaths(4) == 70);
    assert(latticePaths(9) == 48620);
    assert(latticePaths(20) == 137846528820);

    std::cout << "All Tests Passed" << std::endl;

    return 0;
}
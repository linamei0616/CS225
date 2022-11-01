/* Your code here! */
#pragma once
#include <vector>
#include "/workspaces/CS225/mp_mazes/lib/cs225/PNG.h"

class SquareMaze {
    /*
makeMaze :- make a square maze of given height and width without cycles
setWall :- set whether or not a wall exists


canTravel :- can travel in given direction (L, R, U, D)


solveMaze :- stores longest solution from top left corner to a square in the bottom row


drawMaze, drawMazeWithSolution 
    */
    public:
    SquareMaze();
    void makeMaze(int width, int height);
    bool canTravel(int x, int y, int dir) const;
    void setWall(int x, int y, int dir, bool exists);
    std::vector<int> solveMaze();
    // cs225::PNG * drawMaze() const;
    // cs225::PNG * drawMazeWithSolution();

    private:

};
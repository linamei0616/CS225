/* Your code here! */
/*
#pragma once
#include <vector>
#include "/workspaces/CS225/mp_mazes/lib/cs225/PNG.h"
#include "dsets.h"
#include <queue>

using namespace cs225;



class SquareMaze {

    public:
    SquareMaze();

    // makeMaze :- make a square maze of given height and width without cycles
    void makeMaze(int width, int height);

    // canTravel :- can travel in given direction (L, R, U, D)
    bool canTravel(int x, int y, int dir) const;

    // setWall :- set whether or not a wall exists
    void setWall(int x, int y, int dir, bool exists);

    std::vector<int> solveMaze();

    PNG * drawMaze() const;
    //drawMaze, drawMazeWithSolution 
    PNG * drawMazeWithSolution();

    private:
    int width_;
    int height_;
    DisjointSets djset_; // checking acyclic
    std::vector<int>vect; // every cell of the maze laid out in one vector, two vectors = O(N)^2 so 1 might be faster?
        
        the value of a cell corresponds to what wall they have up. Since we only need to keep track of 2 walls,
        0 = no walls
        1 = contains only right wall
        2 = contains only bottom wall
        3 = contains both right and bottom wall
        
};
*/
#include <vector>
#include "cs225/PNG.h"
#include "dsets.h" 
#include <queue>
using namespace std;
using namespace cs225;


class SquareMaze {

  public:
    SquareMaze();
    void makeMaze(int width, int height);
    bool canTravel(int x, int y, int dir) const;
    void setWall(int x, int y, int dir, bool exists);
    vector<int> solveMaze();
    PNG *drawMaze() const;
    PNG *drawMazeWithSolution();
    PNG *drawCreativeMaze();

  private:
    int width_;
    int height_;
    DisjointSets dj_sets; 
    vector<int> cells; 
};
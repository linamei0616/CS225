/* Your code here! */
#include "maze.h"
#include <vector>
#include <algorithm>
#include <map>

using namespace cs225;


SquareMaze::SquareMaze() {
// create empty maze
    width_ = 0;
    height_ = 0;
    dj_sets = DisjointSets();
    cells = vector<int>();
}
void SquareMaze::makeMaze(int width, int height) {
    width_ = width;
    height_ = height;
    int size = width*height; // total number of cells = width*height

    // if it exists, delete it
    // first step is to make a grid
    for (int i = 0; i < size; i++) {
        cells.push_back(3);
    }
    dj_sets.addelements(size); 

    while(dj_sets.size(0) != size){ // while the maze isn't complete since disjoint set still has independent squares
        int rando_cell = rand() % (size);   // Picking a random square: we want a random number between 0 and size
        int rando_wall = rand() % 2; 
        int cell_x = rando_cell % width_;
        int cell_y = rando_cell / width_;
        if(rando_wall == 0) { // removing right wall
            if((rando_cell+1)%width != 0 && dj_sets.find(rando_cell) != dj_sets.find(rando_cell+1)) {
                setWall(cell_x, cell_y, 0, false); 
                dj_sets.setunion(rando_cell, rando_cell+1); 
            } else {
                continue;
            }
        }
        if(rando_wall == 1) { // removing down wall
            if(rando_cell+width < size && dj_sets.find(rando_cell) != dj_sets.find(rando_cell+width)) {
                setWall(cell_x, cell_y, 1, false); 
                dj_sets.setunion(rando_cell, rando_cell+width);  
            } else {
                continue;
            }
        }
    }
}
bool SquareMaze::canTravel(int x, int y, int dir) const {
    int square_to_be_set = y * width_ + x;
    if (dir == 0 && x < width_-1) { // move right x+=1
        // only true if is either no walls (0) or bottom walls (2)
        return (cells[square_to_be_set] == 0 || cells[square_to_be_set] == 2);
    } else if (dir == 1 && y < height_-1) {// move down y+=1
        // only true if either no walls (0) or right walls (1)
        return (cells[square_to_be_set] == 0 || cells[square_to_be_set] == 1);
    } else if (dir == 2 && x > 0) { // move left, x-=1
        // only true if the square before it can move right
        square_to_be_set = (y * width_ + (x-1));
        return (cells[square_to_be_set] == 0 || cells[square_to_be_set] == 2);
    } else if (dir == 3 && y > 0) { //move up, y-=1
        // only true if the square before it can move down
        square_to_be_set = ((y-1) * width_ + x);
        return (cells[square_to_be_set] == 0 || cells[square_to_be_set] == 1);
    }
  return false;
  
}
void SquareMaze::setWall(int x, int y, int dir, bool exists) {
    int square_to_be_set = y * width_ + x;
    if (dir == 0 && exists) { // set right wall
        switch (cells[square_to_be_set]) {
            case 0: // if no walls
                cells[square_to_be_set] =  1; // right wall only
            case 1: // if right wall
                return;
            case 2: // if bottom wall
                cells[square_to_be_set] =  3;
            case 3: // if both wall
                return; 
            default:
                return;
        }
        return;
        }
    // removing walls
    if (dir == 0 && !exists) { // right wall does not exist
        switch (cells[square_to_be_set]) {
            case 0: // if no walls
                return;
            case 1: // if right wall
                cells[square_to_be_set] = 0; // no walls
            case 2: // if bottom wall
                return;
            case 3: // if both wall
                cells[square_to_be_set] = 2; //bottom wall only
            default:
                return;
        }
        return;
    }
    if (dir == 1 && exists) { // set bottom wall
        if (cells[square_to_be_set] == 0) { // if no walls
            cells[square_to_be_set]=2; // bottom wall only
        } else if (cells[square_to_be_set] == 1) { // if right wall
            cells[square_to_be_set]=3; // both walls
        } else if (cells[square_to_be_set] == 2) { // if bottom wall
            return;
        } else if (cells[square_to_be_set] == 3) { // if both wall
            return;
        }
        return;
    }
    // removing walls
    if (dir == 1 && !exists) { // dir == 1 && !exists
        if (cells[square_to_be_set] == 0) { // if no walls
            return;
        } else if (cells[square_to_be_set] == 1) { // if right wall
            return;
        } else if (cells[square_to_be_set] == 2) { // if bottom wall
            cells[square_to_be_set] = 0; // no walls
        } else if (cells[square_to_be_set] == 3) { // if both wall
            cells[square_to_be_set] = 1; // right wall only
        }
    }
}

vector<int> SquareMaze::solveMaze() {
    /*
        function BFS(Graph g, Node* root) := 
        Queue q
        set root to be “visited”
        q.enqueue(root)
        
        while q is not empty do
            v = q.dequeue(root)
            if v is what we were looking for
            return v
            for all edges from v to w in g.adjacentEdges(v) do
            if w is not “visited” then 
                set w as “visited”
                q.enqueue(w)

        ***Need a way to keep track of which cells have already been visited 
        ***Need a way to keep track of potential paths
        ***Need a way to determine which path is the “longest” from the potential path pool
    */
    int size = width_*height_;
    vector<int> path;
    vector<int> length(width_ * height_, -1);
    map<int, int> steps;

    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int top = q.front();
        int x = top % width_;
        int y = top / width_;
        q.pop();

        if (y == height_ - 1) {
            path.push_back(top);
        }
        if (canTravel(x, y, 0) && length[top + 1] < 0) { // right
            length[top + 1] = length[top] + 1;
            q.push(top + 1);
            steps.insert(pair<int, int> (top + 1, top));
        }
        if (canTravel(x, y, 1) && length[top + width_] < 0) { // down
            length[top + width_] = length[top] + 1;
            q.push(top + width_);
            steps.insert(pair<int, int> (top + width_, top));
        }
        if (canTravel(x, y, 2) && length[top - 1] < 0) { // left
            length[top - 1] = length[top] + 1;
            q.push(top - 1);
            steps.insert(pair<int, int> (top - 1, top));
        }
        if (canTravel(x, y, 3) && length[top - width_] < 0) { // up
            length[top - width_] = length[top] + 1;
            q.push(top - width_);
            steps.insert(pair<int, int> (top - width_, top));
        }
    }
    vector<int> output;
    int start = path[width_ - 1];
    while (start != 0) {
        if (start == steps[start] + 1) {
            output.push_back(0);
        } else if (start == steps[start] - 1) {
            output.push_back(2);
        }
        else if (start == steps[start] + width_) {
            output.push_back(1);
        }
        else if (start == steps[start] - width_) {
            output.push_back(3);
        }
        start = steps[start];
    }
    reverse(output.begin(),output.end());
    return output;
}

PNG * SquareMaze::drawMaze() const {
    /*
        First, create a new PNG. Set the dimensions of the PNG to (width*10+1,height*10+1). 
        where height and width were the arguments to makeMaze. Blacken the entire topmost row 
        and leftmost column of pixels, except the entrance (1,0) through (9,0). For each square 
        in the maze, call its maze coordinates (x,y). If the right wall exists, then blacken the 
        pixels with coordinates ((x+1)*10,y*10+k) for k from 0 to 10. If the bottom wall exists,
        then blacken the pixels with coordinates (x*10+k, (y+1)*10) for k from 0 to 10.

        The resulting PNG will look like the sample image, except there will be no exit from the
        maze and the red line will be missing.
    */
    PNG* output = new PNG(width_ * 10 + 1, height_ * 10 + 1);
    for (int i = 0; i < height_ * 10 + 1; i++) { 
        HSLAPixel & pixel = output->getPixel(0, i);
        pixel.l = 0;
    }
    for (int i = 10; i < width_ * 10 + 1; i++) { 
        HSLAPixel & pixel = output->getPixel(i, 0);
        pixel.l = 0;
    }
    for (int x = 0; x < width_; x++) { 
        for (int y = 0; y < height_; y++) {
            int cell = y * width_ + x;
            if (cells[cell] == 1 || cells[cell] == 3) {
                for (int k = 0; k < 11; k++) {
                HSLAPixel & pixel = output->getPixel((x+1)*10, y*10+k);
                pixel.l = 0;
                }
            }
            if (cells[cell] == 2 || cells[cell] == 3) {
                for (int k = 0; k < 11; k++) {
                    HSLAPixel & pixel = output->getPixel(x*10+k, (y+1)*10);
                    pixel.l = 0;
                }
            }
        }
    }
    return output;
}

PNG * SquareMaze::drawMazeWithSolution() {
    /*
        Start at pixel (5,5). Each direction in the solution vector corresponds to a 
        trail of 11 red pixels in the given direction. If the first step is downward, 
        color pixels (5,5) through (5,15) red. (Red is 0,1,0.5,1 in HSLA). Then if the 
        second step is right, color pixels (5,15) through (15,15) red. Then if the third 
        step is up, color pixels (15,15) through (15,5) red. Continue in this manner until
        you get to the end of the solution vector, so that your output looks analogous the above picture.

        Make the exit by undoing the bottom wall of the destination square: call the
        destination maze coordinates (x,y), and whiten the pixels with coordinates 
        (x*10+k, (y+1)*10) for k from 1 to 9.
    */
  PNG* result = drawMaze();
  vector<int> solution = solveMaze();

  int x = 5;
  int y = 5;

  for (size_t i = 0; i < solution.size(); i++) {
    for (int j = 0; j < 10; j++) {
        HSLAPixel & pixel = result->getPixel(x, y);
        if (solution[i] == 0) {
            x++; // right
        } else if (solution[i] == 1) {
            y++; // bottom
        } else if (solution[i] == 2) {
            x--; // left
        } else if (solution[i] == 3) {
            y--; // up      
        }
        pixel.h = 0;
        pixel.s = 1;
        pixel.l = 0.5;
        pixel.a = 1;
        }
  }

  HSLAPixel & pixel = result->getPixel(x, y);
  pixel.h = 0;
  pixel.s = 1;
  pixel.l = 0.5;
  pixel.a = 1;

  x -= 4;
  y += 5;
  for (int i = 0; i < 9; i++) {
    HSLAPixel & pixel = result->getPixel(x + i, y);
    pixel.l = 1;
  }

  return result;
}
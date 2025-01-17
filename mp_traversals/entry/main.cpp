
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.
  // PNG png;
  // png.readFromFile("/workspaces/CS225/mp_traversals/tests/i.png");
  // FloodFilledImage image(png);
  
  // DFS dfs(png, Point(2, 2), 0.5);
  // MyColorPicker c;
  // image.addFloodFill(dfs, c);

  // BFS bfs(png, Point(10, 5), 0.5);
  // MyColorPicker c2;
  // image.addFloodFill(bfs, c2);

  // Animation animation = image.animate(10);

  // PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  // lastFrame.writeToFile("myFloodFill.png");
  // animation.write("myFloodFill.gif");


  // return 0;
  PNG png;
  png.readFromFile("/workspaces/CS225/mp_traversals/flower.png");
  FloodFilledImage image(png);

  BFS bfs(png, Point(150, 0.0), 0.5);
  DFS dfs(png, Point(150, 0.0), 0.5);
  MyColorPicker first;
  image.addFloodFill(bfs, first);
  MyColorPicker second;
  image.addFloodFill(dfs, second);
  Animation animation = image.animate(3000);
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("../myFloodFill.png");
  animation.write("../myFloodFill.gif");
  return 0;

}

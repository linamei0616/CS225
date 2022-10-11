#include <iterator>
#include <cmath>
#include <bits/stdc++.h>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"

using namespace std;

/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * 
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {  
  /** @todo [Part 1] */
  png_=png;
  current_=start;
  tolerance_=tolerance;

  traversal_.push(start);

  // traversal_.push(start);
  // initialiizing
  // vect_.resize(png.width());
  // for (unsigned int i = 0; i < png.width(); i++) {
  //   vect_[i].resize(png.height());
  //   for (unsigned int j=0; j < png.height(); j++) {
  //     vect_[i][j] = false;
  //   }
  // }
  // vect_[start.x][start.y] = true;

}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  DFS * dfs = new DFS(png_, current_, tolerance_);
  return ImageTraversal::Iterator(dfs, current_, png_, tolerance_);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  traversal_.push(point);
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  Point t = traversal_.top();
  traversal_.pop();
  return t;
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  return traversal_.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return traversal_.empty();
}

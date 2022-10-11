#include <cmath>
#include <iterator>
#include <iostream>

#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  traversal_ = NULL;
}
ImageTraversal::Iterator::Iterator(ImageTraversal* traversal, Point point, PNG png, double tolerance) {
  traversal_=traversal;
  png_ = png;
  tolerance_=tolerance;
  start_=point;

  // initialiizing
  vect_.resize(png_.width());
  for (unsigned int i = 0; i < png_.width(); i++) {
    vect_[i].resize(png_.height());
    for (unsigned int j=0; j < png_.height(); j++) {
      vect_[i][j] = false;
    }
  }
  current_= point;
  HSLAPixel start_pixel = png_.getPixel(start_.x, start_.y);
  unsigned int x = current_.x;
  unsigned int y = current_.y;
  vect_[x][y] = true;
  
  //add neighbors
  //right
  if (x+1 < png_.width()) {
    if (calculateDelta(start_pixel, png_.getPixel(x+1, y)) < tolerance_) {
      traversal_->add(Point(x+1,y));
    }
  }
  //bottom
  if (y+1 < png_.height()) {
    if (calculateDelta(start_pixel, png_.getPixel(x, y+1)) < tolerance_) {
      traversal_->add(Point(x,y+1));
    }
  }
  //left
  if (x > 0) {
    if (calculateDelta(start_pixel, png_.getPixel(x-1, y)) < tolerance_) {
      traversal_->add(Point(x-1,y));
    }
  }
  //up
  if (y > 0) {
    if (calculateDelta(start_pixel, png_.getPixel(x, y-1)) < tolerance_) {
      traversal_->add(Point(x,y-1));
    }
  }

}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
 
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  Point top = traversal_->pop();
  while (vect_[top.x][top.y] == true && (!traversal_->empty())) {
    top = traversal_->pop();
  }
  if (traversal_->empty()) {
    traversal_ = NULL;
    return *this;
  }
  current_ = top;

  unsigned int x = current_.x;
  unsigned int y = current_.y;
  vect_[x][y] = true;
  
  //add neighbors
  HSLAPixel start_pixel = png_.getPixel(start_.x, start_.y);
  //right
  if (x+1 < png_.width()) {
    if (calculateDelta(start_pixel, png_.getPixel(x+1, y)) < tolerance_) {
      traversal_->add(Point(x+1,y));
    }
  }
  //bottom
  if (y+1 < png_.height()) {
    if (calculateDelta(start_pixel, png_.getPixel(x, y+1)) < tolerance_) {
      traversal_->add(Point(x,y+1));
    }
  }
  //left
  if (x > 0) {
    if (calculateDelta(start_pixel, png_.getPixel(x-1, y)) < tolerance_) {
      traversal_->add(Point(x-1,y));
    }
  }
  //up
  if (y > 0) {
    if (calculateDelta(start_pixel, png_.getPixel(x, y-1)) < tolerance_) {
      traversal_->add(Point(x,y-1));
    }
  }

  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  return traversal_ != NULL;
}


/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
     if (curDim < 0 || curDim >= Dim) {
      return false;
     }
    if (first[curDim] < second[curDim]) {
      return true;
    } else if (first[curDim] > second[curDim]) {
      return false;
    } else {
      return (first < second);
    }
    return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    int distance=0;
    int to_compare=0;
    for (int i=0; i<Dim; i++) {
      distance+=((potential[i]-target[i])*(potential[i]-target[i]));
      to_compare+=((currentBest[i]-target[i])*(currentBest[i]-target[i]));
    }
    if (distance < to_compare) {
      return true;
    } else if (to_compare < distance) {
      return false;
    } else {
      return potential < currentBest;
    }
     return false;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
  /**
    * @todo Implement this function!
    */
    if (newPoints.empty()) {
      root = NULL;
      size = 0;
      return;
    }
    vector<Point<Dim>> points;
    size = 0;
    points.resize(newPoints.size());
    for (unsigned i = 0; i < newPoints.size(); i++)
    {
      points[i] = newPoints[i];
    }
    root = buildTree(points, 0, points.size()-1, 0);
}

template <int Dim>
unsigned KDTree<Dim>::quickSelectHelper(vector<Point<Dim>>& list, unsigned left, unsigned right, unsigned pivotIndex, int dim) {
  /*
  AMA Slides Pseudocode:
      pivotValue := list[pivotIndex]
      swap list[pivotIndex] and list[right]  // Move pivot to end
      storeIndex := left
      for i from left to right − 1 do
          if list[i] < pivotValue then
              swap list[storeIndex] and list[i]
              increment storeIndex
      swap list[right] and list[storeIndex]  // Move pivot to its final place
      return storeIndex
  */
  	Point<Dim> pivotValue = list[pivotIndex];
    std::swap(list[pivotIndex],list[right]);
  	unsigned storeIndex = left;

  	for (unsigned i = left; i < right; i++){
    	if (smallerDimVal(list[i], pivotValue, dim)) {
        std::swap(list[storeIndex], list[i]);
      		storeIndex++;
    	}
  	}
    std::swap(list[right], list[storeIndex]);
  	return storeIndex;
}

template <int Dim>
Point<Dim>& KDTree<Dim>::quickSelect(vector<Point<Dim>>& list, unsigned left, unsigned right, unsigned k, int dim){
  /*
  AMA Slides Pseudocode:
    if left = right then   // If the list contains only one element,
        return list[left]  // return that element
    pivotIndex  := ...     // select a pivotIndex between left and right,
                           // e.g., left + floor(rand() % (right − left + 1))
    pivotIndex  := partition(list, left, right, pivotIndex)
    // The pivot is in its final sorted position
    if k = pivotIndex then
        return list[k]
    else if k < pivotIndex then
        return select(list, left, pivotIndex − 1, k)
    else
        return select(list, pivotIndex + 1, right, k) 
  */
  if (left == right) {
    return list[left];
  }
  unsigned pivotIndex = k;
  pivotIndex = quickSelectHelper(list, left, right, pivotIndex, dim); 

  if (k == pivotIndex) {
    return list[k];
  } else if(k < pivotIndex) {
    return quickSelect(list, left, pivotIndex - 1, k, dim);
  } else {
    return quickSelect(list, pivotIndex + 1, right, k, dim); 
  }
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::buildTree(vector<Point<Dim>>& list, unsigned left, unsigned right, int dim) {
  /*   AMA Slides Pseudocode:
    function buildTree(points, dim, left, right, curRoot) :=
    // continue if we have points left to include
    if left <= right:
    middle = (left + right) / 2
    rearrange points according to quickselect algorithm
    curRoot = new KDTreeNode at middle point

    recurse left subtree on (dim + 1) % Dim
    recurse right subtree on (dim + 1) % Dim
*/
  if (list.empty() || left >= list.size() || right >= list.size() || left < 0  || right < 0) { // base case & constraints
    return NULL; 
  } 	
  if (left <= right) {
    unsigned median = (left + right) / 2; 
    KDTreeNode* subroot_ = new KDTreeNode(quickSelect(list, left, right, median, dim%Dim)); //     curRoot = new KDTreeNode at middle point
    subroot_->left = buildTree(list, left, median-1, (dim + 1) % Dim); 
    subroot_->right = buildTree(list, median+1, right, (dim + 1) % Dim);  

    return subroot_;
  } else {
    return NULL;
  }
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
  this = new KDTree(other.points);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  if (*this == rhs) {
    return *this;
  }
  del(root);
  this = new KDTree(rhs.points);
  return *this;
}

template <int Dim>
void KDTree<Dim>::del(KDTreeNode*& subroot) {
  if (subroot == NULL) {
    return;
  }
  del(subroot->left);
  del(subroot->right);
  delete subroot;
}
template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
   del(root);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */  
  return findNearestNeighborHelper(root->point, query, root, 0); 
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighborHelper(Point<Dim> nearest, const Point<Dim> query, KDTreeNode *subroot, int dim) const {
/*   AMA Slides Pseudocode:
  if curRoot is bottom:
	return curRoot

  if query[dim] is on left side of curRoot[dim]:
	nearest = recurse on left subtree
  else:
	nearest = recurse on right subtree

  if curRoot is closer:
	update nearest

  radius = squaredDist(query, nearest) // radius between query & nearest
  splitDist = (curRoot -> point[dim] - query[dim]) ^ 2 // split distance on plane

  if radius >= splitDist:
	if already recursed on left:
	  tempNearest = recurse on right subtree
	else:
	  tempNearest = recurse on left subtree
	if tempNearest is closer:
	  update nearest
*/
  // check if it is a leaf node
    if (!subroot->left && !subroot->right) {
      return subroot->point;
    }
    bool traverse_left = false; 
    int new_dim = (dim + 1) % Dim;
  // check if query[dim] is on left side of curRoot[dim], meaning that the value of the point is smaller
    if (smallerDimVal(query, subroot->point, dim)) {
      if (subroot->left) {     // if it is, check if there is a left subtree
        nearest = findNearestNeighborHelper(nearest, query, subroot->left, new_dim);       // recursive call on left subtree
        traverse_left = true;
      }
    } else { // else the value is greater
      nearest = findNearestNeighborHelper(nearest, query, subroot->right, new_dim); // recursive call on right subtree
    }

  // if curRoot is closer, update nearest
    if (shouldReplace(query, nearest, subroot->point)) { 
      nearest = subroot->point;
    }

    double radius = calculate(query, nearest);
    double splitDist = ((subroot->point)[dim] - query[dim]) * ((subroot->point)[dim] - query[dim]);
    
    if (radius >= splitDist) {
      Point<Dim> temp = nearest;
      if (traverse_left) { // 	if already recursed on left; tempNearest = recurse on right subtree
        temp = findNearestNeighborHelper(nearest, query, subroot->right, new_dim);
      } else if (subroot->left){
        temp = findNearestNeighborHelper(nearest, query, subroot->left, new_dim);
      }
      if (shouldReplace(query, nearest, temp)) { // 	if tempNearest is closer; update nearest
        nearest = temp;
      }
    }
    return nearest;
}

template<int Dim>
int KDTree<Dim>::calculate(const Point<Dim> & first, const Point<Dim> & second) const
{
  int radius = 0;
  for (int i=0; i < Dim; i++) {
    radius += (first[i] - second[i]) * (first[i] - second[i]);
  }
  return radius;
}
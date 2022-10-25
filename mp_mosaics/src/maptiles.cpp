/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>

#include "maptiles.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
    int rows = theSource.getRows();
    int cols = theSource.getColumns();
    MosaicCanvas* image = new MosaicCanvas(rows, cols);
    vector<Point<3>> points;
    map<Point<3>, TileImage*> tile_map;
    for (unsigned i = 0; i < theTiles.size(); i++) {
        Point<3> point = convertToXYZ(theTiles[i].getAverageColor());
        points.push_back(point);
        tile_map[point] = &theTiles[i];
    }
    KDTree<3> avg(points);
    for (int i = 0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            TileImage* index = tile_map[avg.findNearestNeighbor(convertToXYZ(theSource.getRegionColor(i, j)))];
            image->setTile(i, j, index);
        }
    }
    return image;
}


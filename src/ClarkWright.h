#ifndef CLARK_WRIGHT_H
#define CLARK_WRIGHT_H

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <iterator>
#include "RoutingModel.h"
class ClarkWright
{
/*! \brief Implementation for Clark Wright Algorithm TBD here. 
 *
 *  (Not implemented yet).
 */

private:
    std::map<int, bool> mVisited;
    int mDepotNode;
    std::vector<Saving> mSavings;
    std::vector<Route> mRoutesCW;

public:
    ClarkWright(RoutingModel model, int depot);
};

#endif
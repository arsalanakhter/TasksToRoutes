#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include "Saving.h"

class Route
{
/*! \brief Basic Route class
 *
 *  A route made of nodes, along with variables defining other properties of node.
 */
private:
    std::vector<Node> mNodes;
    int mLength;
    int mLoad;
    double mCost;  //<! Cost of the whole route
    int mDepot;    //<! Index of Depot node
    int mCapacity; //<! Capacity of the whole route
public:
    Route();
    std::vector<Node> &getNodesOfRoute();
    int getCapacityOfRoute() const;
    void add(Node n);
    double getDistances(int n1, int n2);
    void computeRouteCost();
    void clear();
    void print();
};

#endif
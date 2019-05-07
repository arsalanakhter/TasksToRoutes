#ifndef ROUTING_MODEL_H
#define ROUTING_MODEL_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include <algorithm>
#include "Route.h"

class RoutingModel
{
/*! \brief Basic RoutingModel class
 *
 *  Holds the complete routing model, which contains nodes and routes.
 */

private:
    int mCustomers;   //!< No of customers in the model
    int mVertices;    //!< Total number of nodes in the model
    int mMaxCapacity; //!< maximum Capacity for each route
    int mNoOfRoutes;  //!< number of routes in the model
    //int mCapacityLimitVehicles;
    double mMaxTourLength;      //!< max Tour Length for the model
    std::vector<Node> mNodes;   //!< vector of nodes in the model
    std::vector<Route> mRoutes; //!< vector of routes in the model
    template <typename T>
    void erase(std::vector<T> &vector, T const &value)
    {
        vector.erase(std::remove(begin(vector), end(vector), value), end(vector));
    }

public:
    RoutingModel(int customers, int depots);
    int getCustomers() const;
    std::vector<Node> getNodes() const;
    std::vector<Route> getRoutes() const;
    void readFile(const std::string &fileName);
    void temporarilyAssignNodesToRoutes();
    RoutingModel(const std::string &fileName);
};
#endif
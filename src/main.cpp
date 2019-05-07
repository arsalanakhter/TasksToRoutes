#include "RoutingModel.h"
/*! \brief  main.cpp
 * 			Code for assigning different nodes to routes.
 *      	Currently, it randomly assigns nodes to routes, respecting capacity constraints.
 *
 *  Later, other node-assignment algorithms such ClarkWright or LKH could be added. This gives 
 * 	a starting point.
 */

int main()
{
    std::string fileName = "eil22.vrp";
    RoutingModel model1(fileName);
    //ClarkWright cw(model1, 1);
}

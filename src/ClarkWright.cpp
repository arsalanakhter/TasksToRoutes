#include "ClarkWright.h"
ClarkWright::ClarkWright(RoutingModel model, int depot)
{
    // Initialize visited
    for (auto i = 0; i < model.getCustomers(); i++)
    {
        mVisited.insert(std::pair<int, bool>(i, false));
    }
    // Create routes, with each route created for each customer
    std::vector<Node>::iterator it;
    it = model.getNodes().begin();

    while (it != model.getNodes().end())
    {
        Route r;
        auto routeLoc = 0;
        auto routeIndex = r.getNodesOfRoute().size();
        // Add the depot node
        r.add(model.getNodes()[0]);
        r.getNodesOfRoute()[0].setRouteIndex(routeIndex);
        r.getNodesOfRoute()[0].setRoutePosition(routeLoc);
        routeLoc++;
        r.getNodesOfRoute()[0].setDepot();
        if (it->checkDepot() == 1)
        {
            ++it;
            continue;
        }
        r.add(*it);
        mRoutesCW.push_back(r);
        r.print();
        ++it;
    }
    // Also compute the savings vector for each node to each node
    it = model.getNodes().begin();
    auto it2 = model.getNodes().begin();
    it2++;
    while (it != model.getNodes().end())
    {
        while (it2 != model.getNodes().end())
        {
            auto n1Idx = it->getIndex();
            auto n2Idx = it2->getIndex();
            Saving s(*it, *it2, model.getNodes()[0]);
            ++it;
            ++it2;
        }
    }
}
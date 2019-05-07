#include "Route.h"
Route::Route()
{
    mCost = 0;
    mLoad = 0;
    mLength = 0;
    mDepot = -1;
    mCapacity = 0;
}
std::vector<Node> &Route::getNodesOfRoute()
{
    return mNodes;
}
int Route::getCapacityOfRoute() const
{
    return mCapacity;
}
void Route::add(Node n)
{
    mNodes.push_back(n);
    mLength += 1;
    mCapacity += n.getDemand();
}
double Route::getDistances(int n1, int n2)
{
    auto iterN1 = std::find(mNodes.begin(), mNodes.end(), n1);
    auto iterN2 = std::find(mNodes.begin(), mNodes.end(), n2);
    double x = 0;
    x = std::sqrt(std::pow(
                      iterN1->getX() - iterN2->getX(), 2) +
                  std::pow(
                      iterN1->getY() - iterN2->getY(), 2));
    return x;
}
void Route::computeRouteCost()
{
    auto nodeIter1 = mNodes.begin();
    auto nodeIter2 = mNodes.begin();
    // First, compute costs from each node to each node
    while (nodeIter1 != mNodes.end())
    {
        while (nodeIter2 != mNodes.end())
        {
            double dist = getDistances(nodeIter1->getIndex(), nodeIter2->getIndex());
            nodeIter1->getDistancesToOtherNodes().insert({nodeIter2->getIndex(), dist});
            ++nodeIter2;
        }
        ++nodeIter1;
        nodeIter2 = mNodes.begin();
    }
    // Now, when all node-node costs in the route are computed
    auto iter1 = mNodes.begin();
    auto iter2 = mNodes.begin();
    ++iter2;
    while (iter2 != mNodes.end())
    {
        mCost += iter1->getDistancesToOtherNodes().at(iter2->getIndex());
        ++iter1;
        ++iter2;
    }
}
void Route::clear()
{
    mCost = 0;
    mLoad = 0;
    mLength = 0;
    mDepot = -1;
}

void Route::print()
{
    std::cout << mCost << ": ";
    for (auto i = 0; i < mLength; i++)
    {
        std::cout << mNodes.at(i).getIndex() << ", ";
    }
    std::cout << std::endl;
}
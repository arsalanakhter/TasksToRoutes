#include "Node.h"
bool Node::operator<(const Node &other) const
{
    return mDemand < other.mDemand;
}

bool Node::operator>(const Node &other) const
{
    return mDemand > other.mDemand;
}
bool Node::operator==(const Node &node) const
{
    return this->mIndex == node.mIndex;
}

Node::Node(int i)
{
    mIndex = i;
    mRouteIndex = 0;
    mRoutePosition = 0;
    mX = 0;
    mY = 0;
    mDepot = false;
}

int Node::getX() const
{
    return mX;
}
void Node::setX(int x)
{
    mX = x;
}
int Node::getY() const
{
    return mY;
}
void Node::setY(int y)
{
    mY = y;
}
int Node::getDemand() const
{
    return mDemand;
}
void Node::setDemand(int demand)
{
    mDemand = demand;
}
int Node::getIndex() const
{
    return mIndex;
}
int Node::getRouteIndex() const
{
    return mRouteIndex;
}
void Node::setRouteIndex(int i)
{
    mRouteIndex = i;
}
int Node::getRoutePosition() const
{
    return mRoutePosition;
}
void Node::setRoutePosition(int p)
{
    mRoutePosition = p;
}
std::map<int, double> &Node::getDistancesToOtherNodes()
{
    return mDistancesToOtherNodes;
}
void Node::setDepot()
{
    mDepot = 1;
}
bool Node::checkDepot() const // Return if a node is a depot node or not
{
    return mDepot;
}
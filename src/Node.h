#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <map>
class Node
{
private:
    int mIndex;                                   // Index of the Node
    int mRouteIndex;                              // Index of Route, of which the node is part of
    int mRoutePosition;                           // Position of node in Route
    double mX;                                    // X Coordintaes of node
    double mY;                                    // Y Coordinates of node
    bool mDepot;                                  // 1 if the node is a depot (not implemented yet)
    int mDemand;                                  // Demand at this node
    std::map<int, double> mDistancesToOtherNodes; // Distance of this node to otehr nodes
                                                  // std::map<int, double> mDistancesForCW;
                                                  // std::map<int, int> m_penalities;
                                                  // std::map<int, InsertionCost> mInsertNextTo;
                                                  // std::vector<Node> mIsNearCustomerOf;
                                                  // std::vector<int> mNearCustomers;
                                                  // std::vector<int> mCustomersConsideredAsNeighbours;
public:
    bool operator<(const Node &other) const;
    bool operator>(const Node &other) const;
    bool operator==(const Node &node) const;
    Node(int i);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getDemand() const;
    void setDemand(int demand);
    int getIndex() const;
    int getRouteIndex() const;
    void setRouteIndex(int i);
    int getRoutePosition() const;
    void setRoutePosition(int p);
    std::map<int, double> &getDistancesToOtherNodes();
    void setDepot();
    bool checkDepot() const; // Return if a node is a depot node or not
};
#endif
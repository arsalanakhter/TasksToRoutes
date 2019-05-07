#include "RoutingModel.h"

RoutingModel::RoutingModel(int customers, int depots)
{
    mCustomers = customers;
    mVertices = customers + depots;
    mMaxTourLength = 1e10;
    mMaxCapacity = 0;
}
RoutingModel::RoutingModel(const std::string &fileName)
{
    readFile(fileName);
    temporarilyAssignNodesToRoutes();
    std::vector<Route>::iterator rIter;
    rIter = mRoutes.begin();
    while (rIter != mRoutes.end())
    {
        rIter->computeRouteCost();
        rIter->print();
        ++rIter;
    }
}
int RoutingModel::getCustomers() const
{
    return mCustomers;
}
std::vector<Node> RoutingModel::getNodes() const
{
    return mNodes;
}
std::vector<Route> RoutingModel::getRoutes() const
{
    return mRoutes;
}
void RoutingModel::readFile(const std::string &fileName)
{
    std::ifstream inFile;
    std::string path = __FILE__;                        //gets source code path, include file name
    path = path.substr(0, 1 + path.find_last_of('\\')); //removes file name
    path += fileName;                                   //adds input file to path
    inFile.open(path, std::ios::in);
    if (!inFile)
    {
        std::cerr << "Cannot open the File : " << fileName << std::endl;
    }
    std::string str;
    auto lineNumber = 0;
    bool recordCoords = 0;
    bool recordDemands = 0;
    while (std::getline(inFile, str))
    {
        lineNumber++;
        // Line contains string of length > 0
        if (str.size() > 0)
        {
            if (lineNumber == 2)
            {
                // Extract the number of routes, picking up at keyword 'trucks: '
                std::string str2("trucks: ");
                std::size_t found = str.find(str2);
                std::string remainingString = str.substr(found + str2.length());
                // Extract the number of routes, i.e, unitll a comma
                std::size_t found2 = remainingString.find(',');
                std::string noOfRoutesString = str.substr(found + str2.length(), found2);
                mNoOfRoutes = std::stoi(noOfRoutesString);
            }
            if (lineNumber == 6)
            {
                // Extract the number of routes, picking up at keyword 'trucks: '
                std::string str2("CAPACITY : ");
                std::size_t found = str.find(str2);
                std::string remainingString = str.substr(found + str2.length());
                // Extract the max capacity
                mMaxCapacity = std::stoi(remainingString);
                std::cout << mMaxCapacity << std::endl;
            }
            std::string substring = "NODE_COORD_SECTION";
            std::size_t index = str.find(substring);
            if (index != std::string::npos)
            {
                recordCoords = 1;
                std::cout << recordCoords << std::endl;
                continue;
            }
            substring = "DEMAND_SECTION";
            index = str.find(substring);
            if (index != std::string::npos)
            {
                recordCoords = 0;
                recordDemands = 1;
                std::cout << "Start recording Demands : " << index << std::endl;
                continue;
            }
            substring = "DEPOT_SECTION";
            index = str.find(substring);
            if (index != std::string::npos)
            {
                recordCoords = 0;
                recordDemands = 0;
                std::cout << "End Reading File." << std::endl;
                break;
            }
            if (recordCoords == true)
            {
                std::vector<int> temp;
                std::stringstream strStream(str);
                int n;
                while (strStream >> n)
                {
                    temp.push_back(n);
                }
                Node n1(temp.at(0));
                n1.setX(temp.at(1));
                n1.setY(temp.at(2));
                if (temp.at(0) == 1)
                {
                    n1.setDepot();
                }
                mNodes.push_back(n1);
                mCustomers++;
            }
            if (recordDemands == true)
            {
                std::vector<int> temp;
                std::stringstream strStream(str);
                int n;
                while (strStream >> n)
                {
                    temp.push_back(n);
                }
                mNodes.at(temp[0] - 1).setDemand(temp[1]);
            }
        }
    }
    //Close The File
    inFile.close();
}
void RoutingModel::temporarilyAssignNodesToRoutes()
{
    // Now, Having all the nodes with us, start putting the nodes in
    // routes untill a route is filled to capacity.
    auto tempmNodes = mNodes;
    // Sort the tempNodes by capacity, so that its easier to add them to
    // initial routes
    std::sort(tempmNodes.begin(), tempmNodes.end());
    // std::sort(tempmNodes.begin(), tempmNodes.end(), std::greater<>());
    std::vector<Node>::iterator iter;
    auto it = tempmNodes.begin();

    while (it != tempmNodes.end())
    {
        Route r;
        int routeLoc = 0;
        int routeIndex = mRoutes.size();
        // Add the depot node
        r.add(tempmNodes[0]);
        r.getNodesOfRoute().at(0).setRouteIndex(routeIndex);
        r.getNodesOfRoute().at(0).setRoutePosition(routeLoc);
        ++routeLoc;
        // r.mNodes[0].setDepot(1);
        if (it->checkDepot())
        {
            ++it;
        }

        while (it != tempmNodes.end())
        {
            if (r.getCapacityOfRoute() + it->getDemand() <= mMaxCapacity)
            {
                r.add(*it);
                r.getNodesOfRoute().at(r.getNodesOfRoute().size() - 1).setRouteIndex(routeLoc);
                r.getNodesOfRoute().at(r.getNodesOfRoute().size() - 1).setRoutePosition(routeLoc);
                ++routeLoc;
                ++it;
                if (it == tempmNodes.end())
                {
                    mRoutes.push_back(r);
                    r.print();
                }
            }
            else
            {
                mRoutes.push_back(r);
                r.print();
                break;
            }
        }
    }
}

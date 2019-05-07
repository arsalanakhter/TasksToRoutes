#include "Node.h"
#include <cmath>
class Saving
{
/*! \brief Saving class
 *
 *  Computes Savings for ClarkWright Algorithm (Not implemented yet).
 */

private:
    double mSaving;
    int mFrom;
    int mTo;

public:
    Saving(Node f, Node t, Node d);
    double getDistances(Node n1, Node n2);
    double computeSavings(Node i, Node j, Node d);
};
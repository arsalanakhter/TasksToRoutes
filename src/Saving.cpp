#include "Saving.h"
Saving::Saving(Node f, Node t, Node d)
{
    mFrom = f.getIndex();
    mTo = t.getIndex();
    mSaving = computeSavings(f, t, d);
}
double Saving::getDistances(Node n1, Node n2)
{
    double x = 0;
    x = std::sqrt(std::pow(
                      n1.getX() - n2.getX(), 2) +
                  std::pow(
                      n1.getY() - n2.getY(), 2));
    return x;
}

double Saving::computeSavings(Node i, Node j, Node d)
{
    double s_i0 = getDistances(i, d);
    double s_0j = getDistances(d, j);
    double s_ij = getDistances(i, j);
    return s_i0 + s_0j - s_ij;
}

#include "constantDistribution.h"

/**
 * Constructor
 */
ConstantDistribution::ConstantDistribution(float probability):
    TabulatedDistribution()
{
    setDistribution({{0, probability}});
}

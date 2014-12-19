#include "tableDistribution.h"

/**
 * Constructor
 */
TableDistribution::TableDistribution(map<unsigned long, float> distribution):
    TabulatedDistribution()
{
    setDistribution(distribution);
}

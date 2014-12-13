#include "generatedDistribution.h"

/**
 * Constructor
 */
GeneratedDistribution::GeneratedDistribution(unsigned long neverValue, unsigned long alwaysValue):
    TabulatedDistribution(),
    my_neverValue(neverValue),
    my_alwaysValue(alwaysValue)
{
}

/**
 * Generate the distribution
 */
void GeneratedDistribution::generateDistribution()
{
    map<unsigned long, float> distribution;

    for (
        unsigned long value = min(my_neverValue, my_alwaysValue);
        value <= max(my_neverValue, my_alwaysValue);
        ++value
    ) {
        distribution[value] = generator(value, my_neverValue, my_alwaysValue);
    }

    setDistribution(distribution);
}

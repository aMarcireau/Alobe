#include "tabulatedDistribution.h"

/**
 * Constructor
 */
TabulatedDistribution::TabulatedDistribution():
    my_distribution(map<unsigned long, float>())
{
}

/**
 * Setter for the distribution
 */
void TabulatedDistribution::setDistribution(map<unsigned long, float> distribution)
{
    my_distribution = distribution;
}

/**
 * Get probability value
 */
float TabulatedDistribution::getProbability(unsigned long value)
{
    map<unsigned long, float>::iterator distributionIterator = my_distribution.find(value);
    if (distributionIterator != my_distribution.end()) {
        return distributionIterator->second;
    }

    for (
        map<unsigned long, float>::iterator distributionIterator = my_distribution.begin();
        distributionIterator != my_distribution.end();
        ++distributionIterator
    ) {
        if (value < distributionIterator->first) {
            if (distributionIterator == my_distribution.begin()) {
                return distributionIterator->second;
            } else {
                map<unsigned long, float>::iterator nextDistributionIterator(distributionIterator);
                --nextDistributionIterator;

                return (distributionIterator->second + (value - distributionIterator->first) * (nextDistributionIterator->second - distributionIterator->second)
                    / (nextDistributionIterator->first - distributionIterator->first));
            }
        }
    }

    return my_distribution.rbegin()->second;
}

/**
 * Get a boolean decision for the given value
 */
bool TabulatedDistribution::getDecision(unsigned long value)
{
    return (rand() < getProbability(value) * RAND_MAX);
}

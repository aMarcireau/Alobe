#include "exponentialDistribution.h"

/**
 * Constructor
 */
ExponentialDistribution::ExponentialDistribution(unsigned long neverValue, unsigned long alwaysValue):
    GeneratedDistribution(neverValue, alwaysValue)
{
    generateDistribution();
}

/**
 * Get the function value
 */
float ExponentialDistribution::generator(unsigned long value, unsigned long neverValue, unsigned long alwaysValue)
{
    return pow((((float)(value) - (float)(neverValue)) / ((float)(alwaysValue) - (float)(neverValue))), 2);
}

#ifndef __ALOBE__EXPONENTIAL_DISTRIBUTION__
#define __ALOBE__EXPONENTIAL_DISTRIBUTION__

#include <math.h>

#include "generatedDistribution.h"

/**
 * Exponential distribution
 * Inherits GeneratedDistribution
 *
 * An exponential distribution
 */
class ExponentialDistribution: public GeneratedDistribution
{
    public:
        ExponentialDistribution(unsigned long neverValue, unsigned long alwaysValue);

    private:
        float generator(unsigned long value, unsigned long neverValue, unsigned long alwaysValue); // Get the function value
};

#endif // __ALOBE__EXPONENTIAL_DISTRIBUTION__

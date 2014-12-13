#ifndef __ALOBE__TABLE_DISTRIBUTION__
#define __ALOBE__TABLE_DISTRIBUTION__

#include <math.h>
#include <map>

#include "tabulatedDistribution.h"

/**
 * Exponential distribution
 * Inherits TabulatedDistribution
 *
 * A table distribution
 */
class TableDistribution: public TabulatedDistribution
{
    public:
        TableDistribution(map<unsigned long, float> distribution);
};

#endif // __ALOBE__TABLE_DISTRIBUTION__

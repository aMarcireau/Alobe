#ifndef __ALOBE__TABULATED_DISTRIBUTION__
#define __ALOBE__TABULATED_DISTRIBUTION__

#include <map>
#include <stdlib.h>
#include <string>

using namespace std;

/**
 * Tabulated distribution
 *
 * A tabulated distribution for probabilities calculations
 */
class TabulatedDistribution
{
    public:
        TabulatedDistribution();
        void setDistribution(map<unsigned long, float> distribution); // Setter for the distribution
        float getProbability(unsigned long value);                    // Get probability value
        bool getDecision(unsigned long value);                        // Get a boolean decision for the given value
    private:
        map<unsigned long, float> my_distribution;
};

#endif // __ALOBE__TABULATED_DISTRIBUTION__

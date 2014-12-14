#ifndef __ALOBE__TABULATED_DISTRIBUTION__
#define __ALOBE__TABULATED_DISTRIBUTION__

#include <map>
#include <stdlib.h>
#include <string>

using namespace std;

/**
 * <<Abstract>> Tabulated distribution
 *
 * A tabulated distribution for probabilities calculations
 */
class TabulatedDistribution
{
    public:
        TabulatedDistribution();
        virtual ~TabulatedDistribution() = default;
        void setDistribution(map<unsigned long, float> distribution); // Setter for the distribution
        float getProbability(unsigned long value = 0);                // Get probability value
        bool getDecision(unsigned long value = 0);                    // Get a boolean decision for the given value
    private:
        map<unsigned long, float> my_distribution;
};

#endif // __ALOBE__TABULATED_DISTRIBUTION__

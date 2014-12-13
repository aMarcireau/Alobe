#ifndef __ALOBE__GENERATED_DISTRIBUTION__
#define __ALOBE__GENERATED_DISTRIBUTION__

#include <map>

#include "tabulatedDistribution.h"

using namespace std;

/**
 * <<Abstract>> Generated distribution
 * Inherits TabulatedDistribution
 *
 * A distribution generator model
 */
class GeneratedDistribution: public TabulatedDistribution
{
    public:
        GeneratedDistribution(unsigned long neverValue, unsigned long alwaysValue);
        virtual ~GeneratedDistribution() = default;
        void generateDistribution();                                                                           // Generate the distribution
    private:
        virtual float generator(unsigned long value, unsigned long neverValue, unsigned long alwaysValue) = 0; // Get the function value
        unsigned long my_neverValue;
        unsigned long my_alwaysValue;
};

#endif // __ALOBE__GENERATED_DISTRIBUTION__

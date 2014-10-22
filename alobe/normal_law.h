#ifndef __alobe__normal_law__
#define __alobe__normal_law__

#include <stdio.h>
#include <random>

using namespace std;

/**
 * Normal_law
 * Inherits normal_distribution
 *
 * creates a normal_distribution en calculates the corresponding probability
 */

class Normal_law
{
public:
    Normal_law(float lambda, float mu);
    
private:
    float mean;
    float std_deviation;
    normal_distribution<double> distribution;

};

#endif /* defined(__alobe__normal_law__) */

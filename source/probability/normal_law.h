#ifndef __alobe__normal_law__
#define __alobe__normal_law__

#include <stdio.h>
#include <random>
#include "proba.h"
#include <iostream>

using namespace std;

/**
 * Normal_law
 * Inherits normal_distribution
 *
 * creates a normal_distribution en calculates the corresponding probability
 */

class Normal_law : public Proba
{
public:
    Normal_law(float mean, float std_deviation);
    float generate_rdm_value();

private:
    normal_distribution<> normal_law_distribution;
};

#endif /* defined(__alobe__normal_law__) */

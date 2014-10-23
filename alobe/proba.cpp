#include "proba.h"
#include "normal_law.h"
#include <map>

using namespace std;

/**
 * Constructor
 */
Proba::Proba()
{
    
}

// function that calculates the surface beneath the distribution
unsigned long Proba::integrate(unsigned long variable)
{
    return 0;
};

unsigned long Proba::rectangle_area()
{
    return 0;
};

float Proba::generate_rdm_value()
{
    return 0;
};


map<int, unsigned long> Proba::sample(unsigned long sampling)
{
    map<int, unsigned long> distrib;
    for(int iterator=0; iterator < sampling; ++iterator)
    {
        ++distrib[round(generate_rdm_value())];
    }
    return distrib;
};


// function that calculate a random value between 0 and 1

// function that return the value of proba (boolean)
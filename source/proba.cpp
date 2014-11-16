#include "proba.h"
#include "iostream"
#include "normal_law.h"
#include "line_law.h"
#include <map>
#include <string>

using namespace std;

/**
 * Constructor
 */
Proba::Proba()
{
    map<int, float> my_distrib;
}

// function that calculate a random value between 0 and 1
bool Proba::roll_of_dice(int condition, unsigned long sampling)
{
    
    sample(sampling);
    double dice = (double) rand()/RAND_MAX;
    return (dice > my_distrib[condition]);
};


float Proba::generate_rdm_value(int iterator, unsigned long sampling)
{
    cout << "Warning ! Use of a virtual method";
    return 0;
};


void Proba::sample(unsigned long sampling)
{
    for(int iterator =0; iterator < sampling; ++iterator)
    {
        my_distrib[iterator] = this->generate_rdm_value(iterator, sampling);
    }
};

void Proba::print_my_distrib()
{
    for (auto p : my_distrib)
    {
        cout << p.first << " - " << p.second << '\n';
    }
}




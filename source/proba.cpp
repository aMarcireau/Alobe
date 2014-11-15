#include "proba.h"
#include "iostream"
#include "normal_law.h"
#include <map>
#include <string>

using namespace std;

/**
 * Constructor
 */
Proba::Proba()
{
    map<int, unsigned long> distrib;
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
    cout << "Warning ! Use of a virtual method";
    return 0;
};


map<int, unsigned long> Proba::sample(unsigned long sampling)
{
    
    for(int iterator=0; iterator < sampling; ++iterator)
    {
        ++my_distrib[round(this->generate_rdm_value())];
    }
    normalized();
    return my_distrib;
};

string Proba::map_to_string()
{
    string str;
    for(auto p : my_distrib) {
        str +=  to_string(p.first)+ " " + to_string(p.second) + '\n';
    };
    return str;
};
//function that get the max on
void normalized()
{
    float max_val = 0;
    for (auto p : my_distrib){
        if (p.second > max_val)
        {
            max_val= p.second;
        }
    }
    for (auto p : my_distrib)
    {
        
        p.second=p.second/max_val*1000;
        cout << to_string(p.second) + '\n';
    }
};

// function that calculate a random value between 0 and 1

// function that return the value of proba (boolean)
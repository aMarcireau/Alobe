//
//  proba.h
//  alobe
//
//  Created by Xavier J on 22/10/2014.
//  Copyright (c) 2014 Xavier. All rights reserved.
//


/* proba
 * uses normal_distribution
 * 
 * manages the proba. Not very clean !
 */


#ifndef __alobe__proba__
#define __alobe__proba__
#include <stdio.h>
#include <map>
using namespace std;

class Proba
{
public:
    Proba();
    virtual float generate_rdm_value();
    unsigned long get_proba(unsigned long variable);
    string map_to_string();
    map<int, unsigned long> sample(unsigned long sampling); // sample the distribution
    
private:
    map<int, unsigned long> my_distrib;
    unsigned long integrate(unsigned long variable); // integrate the sampled distribution
    unsigned long rectangle_area(); // calculate the rectangle area
    void normalized(); // normalized the law. Sets max value to 1
};

#endif /* defined(__alobe__proba__) */

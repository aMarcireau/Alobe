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
    virtual float generate_rdm_value(int iterator, unsigned long sampling);
    bool roll_of_dice(int condition, unsigned long sampling);
    
private:
    map<int, float> my_distrib;
    void sample(unsigned long sampling); // sample the distribution
    void print_my_distrib();
};

#endif /* defined(__alobe__proba__) */

//
//  normal_law.cpp
//  alobe
//
//  Created by Xavier J on 22/10/2014.
//  Copyright (c) 2014 Xavier. All rights reserved.
//

#include "normal_law.h"

// Normal is created for each proba. For instance the age normal law always remains during the game. 


/**
 * Constructor
 */
Normal_law::Normal_law(float lambda, float mu)
{
    mean = mu;
    std_deviation = lambda;
    normal_distribution<double> distribution(mean,std_deviation);
};


// function that calculates the surface beneath the distribution

// function that calculate a random value between 0 and 1

// function that return the value of proba (boolean)
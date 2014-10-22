//
//  normal_law.cpp
//  alobe
//
//  Created by Xavier J on 22/10/2014.
//  Copyright (c) 2014 Xavier. All rights reserved.
//

#include "normal_law.h"

/**
 * Constructor
 */
Normal_law::Normal_law(float lambda, float mu)
{
    mean = mu;
    std_deviation = lambda;
    normal_distribution<double> distribution(mean,std_deviation);
};
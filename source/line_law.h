

#ifndef __alobe__line_law__
#define __alobe__line_law__

#include <stdio.h>
#include <random>
#include "proba.h"
#include <iostream>

using namespace std;

class Line_law : public Proba
{
public:
    Line_law();
    float generate_rdm_value(int iterator, unsigned long sampling);
    
private:
};


#endif /* defined(__alobe__line_law__) */

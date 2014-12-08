#ifndef __ALOBE__UTILITIES__
#define __ALOBE__UTILITIES__

#include <iostream>

using namespace std;

/**
 * Collection of functions
 * used throughout the code
 */
long long llModulo(long long dividend, long long divisor); // Calculate dividend mod(divisor) for long long numbers
unsigned long intervalToCoordinate(
    unsigned long minimum,
    unsigned long maximum,
    unsigned long total,
    unsigned long position
);                                                         // Calculate the position of an element in a divided interval

#endif // __ALOBE__UTILITIES__

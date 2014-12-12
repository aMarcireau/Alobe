#ifndef __ALOBE__UTILITIES__
#define __ALOBE__UTILITIES__

#include <iostream>
#include <vector>

using namespace std;

/**
 * Collection of functions
 * used throughout the code
 */
long long llModulo(long long dividend, long long divisor);   // Calculate dividend mod(divisor) for long long numbers
unsigned long intervalToCoordinate(
    unsigned long minimum,
    unsigned long length,
    unsigned long total,
    unsigned long position
);                                                           // Calculate the position of an element in a divided interval
vector<unsigned long> hexadecimalToRGB(unsigned long color); // Convert hexadecimal color to RGB
unsigned long smoothedMove(
    unsigned long position,
    long long speed,
    unsigned long minimum,
    unsigned long maximum,
    float turnover
);                                                           // Smoothed move next step

#endif // __ALOBE__UTILITIES__

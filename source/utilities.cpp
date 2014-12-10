#include "utilities.h"

/**
 * Calculate dividend mod(divisor) for long long numbers
 */
long long llModulo(long long dividend, long long divisor){
    return (dividend % divisor + divisor) % divisor;
}

/**
 * Calculate the coordinates of the 'position' element in the interval [minimum, maximum] divided by 'total' elements
 */
unsigned long intervalToCoordinate(unsigned long minimum, unsigned long maximum, unsigned long total, unsigned long position
)
{
    if (minimum > maximum) {
        throw logic_error("Minimum is larger than maximum");
    }
    if (position > total) {
        throw logic_error("Position is larger than total");
    }

    return minimum + (unsigned long)(((double)(maximum - minimum)) / total * position);
}

/**
 * Convert hexadecimal color to RGB
 */
vector<unsigned long> hexadecimalToRGB(unsigned long color)
{
    return {color / 0x10000, (color / 0x100) % 0x100, color % 0x100};
}

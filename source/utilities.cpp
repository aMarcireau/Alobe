
#include "utilities.h"

/**
 * Calculate dividend mod(divisor) for long long numbers
 */
long long llModulo(long long dividend, long long divisor){
    return (dividend % divisor + divisor) % divisor;
}

/**
 * Calculate the coordinates of the 'position' element in the interval [minimum, minimum + length] divided by 'total' elements
 */
unsigned long intervalToCoordinate(unsigned long minimum, unsigned long length, unsigned long total, unsigned long position
)
{
    if (position > total) {
        throw out_of_range("total");
    }

    return minimum + (unsigned long)((double)(length) / total * position);
}

/**
 * Convert hexadecimal color to RGB
 */
vector<unsigned long> hexadecimalToRGB(unsigned long color)
{
    return {color / 0x10000, (color / 0x100) % 0x100, color % 0x100};
}


/**
 * Smoothed move next step
 */
unsigned long smoothedMove(unsigned long position, long long speed, unsigned long minimum, unsigned long maximum, float turnover)
{
    if (position < minimum or position > maximum) {
        throw out_of_range("position");
    }
    if (turnover < 0 or turnover > 1) {
        throw out_of_range("turnover");
    }

    long long newSpeed;
    if (position == minimum) {
        if (rand() % 2 == 0) {
            newSpeed = 0;
        } else {
            newSpeed = 1;
        }
    } else if (position == maximum) {
        if (rand() % 2 == 0) {
            newSpeed = -1;
        } else {
            newSpeed = 0;
        }
    } else {
        if (rand() < turnover * RAND_MAX) {
            if (speed > 0 or speed < 0) {
                newSpeed = 0;
            } else {
                if (rand() % 2 == 0) {
                    newSpeed = -1;
                } else {
                    newSpeed = 1;
                }
            }
        } else {
            if (speed < 0) {
                newSpeed = -1;
            } else if (speed > 0) {
                newSpeed = 1;
            } else {
                newSpeed = 0;
            }
        }
    }

    return position + newSpeed;
}

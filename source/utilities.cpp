#include "utilities.h"

/**
 * Calculate dividend mod(divisor) for long long numbers
 */
long long llModulo(long long dividend, long long divisor){
    return (dividend % divisor + divisor) % dividend;
}

#ifndef __ALOBE__TOKEN_DISTRIBUTION__
#define __ALOBE__TOKEN_DISTRIBUTION__

#include <map>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;

/**
 * Token distribution
 *
 * Decision based on a token distribution
 */
template <class T>
class TokenDistribution
{
    public:
        TokenDistribution();
        T getDecision(vector<pair<T, unsigned long> > tokensByElement); // Choose an element among the given token distribution
};

#endif // __ALOBE__TOKEN_DISTRIBUTION__

#include "tokenDistribution.h"

/**
 * Constructor
 */
template <class T>
TokenDistribution<T>::TokenDistribution()
{
}

/**
 * Choose an element among the given token distribution
 */
template <class T>
T TokenDistribution<T>::getDecision(vector<pair<T, unsigned long> > tokensByElement)
{
    unsigned long tokenSum = 0;
    for (
        typename vector<pair<T, unsigned long> >::iterator tokensByElementIterator = tokensByElement.begin();
        tokensByElementIterator != tokensByElement.end();
        ++tokensByElementIterator
    ) {
        tokenSum += tokensByElementIterator->second;
    }

    unsigned long decision = rand() % tokenSum;
    for (
        typename vector<pair<T, unsigned long> >::iterator tokensByElementIterator = tokensByElement.begin();
        tokensByElementIterator != tokensByElement.end();
        ++tokensByElementIterator
    ) {
        if (decision < tokensByElementIterator->second) {
            return tokensByElementIterator->first;
        } else {
            decision -= tokensByElementIterator->second;
        }
    }

    return tokensByElement.back().first;
}

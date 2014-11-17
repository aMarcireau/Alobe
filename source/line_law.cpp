#include "line_law.h"
#include "normal_law.h"

using namespace std;

/**
 * Constructor
 */
Line_law::Line_law():
    Proba()
{};

float Line_law::generate_rdm_value(int iterator, unsigned long sampling)
{
    return float(iterator)/float(sampling);
};

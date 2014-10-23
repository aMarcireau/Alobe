#include "normal_law.h"

// Normal is created for each proba. For instance the age normal law always remains during the game. 
using namespace std;

/**
 * Constructor
 */
Normal_law::Normal_law(float mean, float std_deviation):
    Proba(),
    normal_law_distribution(normal_distribution<double>(mean,std_deviation))
{};

float Normal_law::generate_rdm_value()
{
    random_device rd;
    mt19937 gen(rd());
    return normal_law_distribution(gen);
};
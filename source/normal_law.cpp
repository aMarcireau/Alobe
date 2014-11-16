#include "normal_law.h"

// Normal is created for each proba. For instance the age normal law always remains during the game. 
using namespace std;

/**
 * Constructor
 */
Normal_law::Normal_law(float mean, float std_deviation):
    Proba(),
    normal_law_distribution(normal_distribution<double>(mean,std_deviation)),
    temporary_distrib()
{
    populate_temporary_distrib();
    normalized();
};

float Normal_law::generate_rdm_value(int iterator, unsigned long sampling)
{
    float ratio = float(iterator)/float(sampling)*temp_distrib_size();
    return get_v(floor(ratio))+(ratio-floor(ratio))*(get_v(ceil(ratio))-get_v(floor(ratio)));
};

float Normal_law::get_v(int pos)
{
    return temporary_distrib[pos];
}

unsigned int Normal_law::temp_distrib_size()
{
    int max = 0;
    for(auto p : temporary_distrib)
    {
        if (int(p.first) > max)
        {
            max = p.first;
        }
    }
    return max;
}

// creat a rdm set according to normal distribution. Approximately 10 values
float Normal_law::generate_law_values()
{
    random_device rd;
    mt19937 gen(rd());
    return normal_law_distribution(gen);
};

void Normal_law::populate_temporary_distrib()
{
    for(int iterator=0; iterator < 50; ++iterator)
    {
        ++temporary_distrib[this->generate_law_values()];
    }
};

//function that get the max on
void Normal_law::normalized()
{
    float max_val = 0;
    map<int, float> local_distrib = temporary_distrib;
    for (auto p : local_distrib){
        if (p.second > max_val)
        {
            max_val= p.second;
        }
    }
    for (auto p : local_distrib)
    {
        if (p.first >= 0)
        {
            local_distrib[p.first]=p.second/max_val;
        }
        else
        {
            local_distrib.erase(p.first);
        }
    }
    temporary_distrib = local_distrib;
};

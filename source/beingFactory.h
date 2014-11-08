#ifndef __ALOBE__BEING_FACTORY__
#define __ALOBE__BEING_FACTORY__

#include <string>

#include "being.h"
#include "chromosome.h"
#include "behaviour.h"
#include "state.h"

using namespace std;

/**
 * Being factory
 *
 * The being factory generates beings.
 * It can create a being with either a random set of chromosomes,
 * or from its parents'
 *
 * The being factory binds default states and behaviours to the being,
 * based on its set of chromosomes.
 *
 * The factory also acts as a container for the chromosomes,
 * and default states of a simulation.
 */
class BeingFactory
{
    public:
        BeingFactory();

    private:
        vector<shared_ptr<Chromosome> > my_chromosomes;
        vector<shared_ptr<Behaviour> > my_behaviours;
        vector<string> my_states;
};

#endif // __ALOBE__BEING_FACTORY__

#ifndef __ALOBE__BEING_FACTORY__
#define __ALOBE__BEING_FACTORY__

#include <string>
#include <memory>
#include <map>
#include <stdlib.h>
#include <math.h>

#include "being.h"
#include "state.h"
#include "behavior.h"
#include "female.h"
#include "male.h"
#include "extrovertMigration.h"
#include "neutralMigration.h"
#include "introvertMigration.h"

using namespace std;

/**
 * Being factory
 *
 * The being factory generates beings.
 * It can create a being with either a random set of chromosomes,
 * or from its parents'
 *
 * The being factory binds default states to the being,
 * and generate its class based on its set of chromosomes.
 *
 * The factory also acts as a container for the default behaviors
 * and states of a population.
 */
class BeingFactory
{
    public:
        BeingFactory();
        unique_ptr<Being> generateBeing();                                                                   // Generate a random being
        unique_ptr<Being> generateBeing(Being & firstParent, Being & secondParent);                          // Generate a being from a couple
        unique_ptr<Being> generateBeing(map<string, vector<string> > chromosomes);                           // Generate a being from a set of chromosomes

    private:
        void initialize();                                                                                   // Initialize the being factory

    private:
        static const map<string, pair<vector<string>, map<unsigned long, string> > > behaviorsByChromosomes; // Map the behaviors to the chromosomes combinations
        map<string, vector<string> > my_chromosomes;
        map<string, unique_ptr<State> > my_states;
        map<string, map<string, shared_ptr<Behavior> > > my_behaviors;
};

#endif // __ALOBE__BEING_FACTORY__

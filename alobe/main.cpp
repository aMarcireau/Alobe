#include "simulation.h"
#include "stepper.h"
#include "actor.h"

using namespace std;

int main() {
    unique_ptr<Simulation> simulation = make_unique<Simulation>(make_unique<Stepper>());

    simulation->toStep(10);

    return 0;
}

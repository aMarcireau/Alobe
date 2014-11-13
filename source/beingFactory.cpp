#include "beingFactory.h"

/**
 * Map the behaviors to the chromosomes combinations
 */
const map<string, pair<vector<string>, map<unsigned long, string> > > BeingFactory::behaviorsByChromosomes = {
    {"gender", {
        {"X", "Y"}, {
            {11, "male"},
            {20, "female"}
        }}
    },
    {"migration", {
        {"extrovert", "introvert"}, {
            {02, "introvert"},
            {11, "neutral"},
            {20, "extrovert"}
        }}
    }
};

/**
 * Constructor
 */
BeingFactory::BeingFactory():
    my_chromosomes(map<string, vector<string> >()),
    my_states(map<string, unique_ptr<State> >()),
    my_behaviors(map<string, map<string, shared_ptr<Behavior> > >())
{
    initialize();
}

/**
 * Initialize the being factory
 */
void BeingFactory::initialize()
{
    my_chromosomes["gender"].push_back("X");
    my_chromosomes["gender"].push_back("Y");
    my_chromosomes["migration"].push_back("extrovert");
    my_chromosomes["migration"].push_back("introvert");

    my_states["age"] =  make_unique<State>(100);

    my_behaviors["gender"]["female"] = make_unique<Female>();
    my_behaviors["gender"]["male"] = make_unique<Male>();
    my_behaviors["migration"]["extrovert"] = make_shared<ExtrovertMigration>();
    my_behaviors["migration"]["neutral"] = make_shared<NeutralMigration>();
    my_behaviors["migration"]["introvert"] = make_shared<IntrovertMigration>();
}

/**
 * Generate a random being
 */
unique_ptr<Being> BeingFactory::generateBeing()
{
    map<string, vector<string> > randomChromosomes = map<string, vector<string> >();

    for (
        map<string, vector<string> >::iterator chromosomeTypeIterator = my_chromosomes.begin();
        chromosomeTypeIterator != my_chromosomes.end();
        ++chromosomeTypeIterator
    ) {
        if (chromosomeTypeIterator->first == "gender") {
            if (rand() % 2 == 0) {
                randomChromosomes[chromosomeTypeIterator->first].push_back((chromosomeTypeIterator->second)[0]);
                randomChromosomes[chromosomeTypeIterator->first].push_back((chromosomeTypeIterator->second)[0]);
            } else {
                randomChromosomes[chromosomeTypeIterator->first].push_back((chromosomeTypeIterator->second)[0]);
                randomChromosomes[chromosomeTypeIterator->first].push_back((chromosomeTypeIterator->second)[1]);
            }
        } else {
            randomChromosomes[chromosomeTypeIterator->first].push_back((chromosomeTypeIterator->second)[rand() % (chromosomeTypeIterator->second).size()]);
            randomChromosomes[chromosomeTypeIterator->first].push_back((chromosomeTypeIterator->second)[rand() % (chromosomeTypeIterator->second).size()]);
        }
    }

    return generateBeing(randomChromosomes);
}

/**
 * Generate a being from a couple
 */
unique_ptr<Being> BeingFactory::generateBeing(Being & firstParent, Being & secondParent)
{
    if (dynamic_cast<Gender &>(*(firstParent.getBehavior("gender"))).get() == dynamic_cast<Gender &>(*(secondParent.getBehavior("gender"))).get()) {
        throw logic_error("Parents share the same gender");
    }

    map<string, vector<string> > mixedChromosomes = map<string, vector<string> >();

    for (
        map<string, vector<string> >::iterator chromosomeTypeIterator = my_chromosomes.begin();
        chromosomeTypeIterator != my_chromosomes.end();
        ++chromosomeTypeIterator
    ) {
        mixedChromosomes[chromosomeTypeIterator->first].push_back(
            ((firstParent.getChromosomes())[chromosomeTypeIterator->first])[rand() % 2]
        );
        mixedChromosomes[chromosomeTypeIterator->first].push_back(
            ((secondParent.getChromosomes())[chromosomeTypeIterator->first])[rand() % 2]
        );
    }

    unique_ptr<Being> child =  move(generateBeing(mixedChromosomes));

    child->addParent(firstParent);
    child->addParent(secondParent);
    firstParent.addChild(*child);
    secondParent.addChild(*child);

    return child;
}

/**
 * Generate a being from a set of chromosomes
 */
unique_ptr<Being> BeingFactory::generateBeing(map<string, vector<string> > chromosomes)
{
    unique_ptr<Being> being = make_unique<Being>(to_string(rand()), chromosomes);

    for (
        map<string, unique_ptr<State> >::iterator stateIterator = my_states.begin();
        stateIterator != my_states.end();
        ++stateIterator
    ) {
        being->addState(stateIterator->first, make_unique<State>(*((stateIterator->second).get())));
    }

    for (
        map<string, vector<string> >::iterator chromosomeTypeIterator = my_chromosomes.begin();
        chromosomeTypeIterator != my_chromosomes.end();
        ++chromosomeTypeIterator
    ) {
        unsigned long behaviorKey = 0;
        unsigned long mappedChromosomesSize = ((behaviorsByChromosomes.at(chromosomeTypeIterator->first)).first).size();
        for (
            unsigned long chromosomeIndex = 0;
            chromosomeIndex != mappedChromosomesSize;
            ++chromosomeIndex
        ) {
            behaviorKey += count(
                (chromosomeTypeIterator->second).begin(),
                (chromosomeTypeIterator->second).end(),
                ((behaviorsByChromosomes.at(chromosomeTypeIterator->first)).first).at(chromosomeIndex)
            ) * pow(10, chromosomeIndex);
        }

        being->addBehavior(chromosomeTypeIterator->first, my_behaviors[chromosomeTypeIterator->first][
            ((behaviorsByChromosomes.at(chromosomeTypeIterator->first)).second).at(behaviorKey)
        ]);
    }

    return being;
}

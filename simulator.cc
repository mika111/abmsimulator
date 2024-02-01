#include "simulationenv.h"
#include <iostream>
#include <random>
#include <thread>
#include <vector>
int main()
{
    SimulationEnv simenv(321,123);
    simenv.spawnagents<Prey>(100);
    Agent *pointer = new Prey(100,100);
    std::vector<std::thread> agentthreads;
    std::vector<Agent*> agents;
    return 1;
}
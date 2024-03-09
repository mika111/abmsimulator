#include "simulationenv.cc"
#include <iostream>
#include <random>
#include <thread>
#include <vector>
int main()
{     
    SimulationEnv simenv(321,123);
    //simenv.spawnagents<Prey>(100);
    //Agent *pointer = new Prey(10,12);
    //Agent *eat = new Prey(11,11);
    std::vector<std::thread> agentthreads;
    std::vector<Agent*> agents;
    std::cout << "compiled";
    return 1;

}
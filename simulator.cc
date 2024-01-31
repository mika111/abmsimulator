#include "simulationenv.h"
#include <iostream>
#include <random>
#include <thread>
#include <vector>
int main()
{
    SimulationEnv simenv(321,123);
    simenv.initprey(100);
    Agent *pointer = new Prey();
    std::vector<std::thread> agentthreads;
    std::vector<Agent*> agents;
    for(int i = 0;i <=100;i++) 
    {
    Agent *agentptr = new Prey();
    agents.emplace_back(agentptr);
    }
    for (int j = 0;j<=100;j++)
    {std::cout << agents[j]->agenttype()<< " " << j << std::endl;}
    std::cout << simenv.x << " " << simenv.y<< std::endl;
    return 1;
}
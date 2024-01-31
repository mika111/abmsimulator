#pragma once
#include "AgentClass.h"
#include "preyagent.h"
#include <random>
#include <unordered_map>
#include <thread>

struct hashcoords {
    //hash function so i can use a hash map for the coordinates of the agents
std::size_t operator()(const std::pair<int,int> &coords) 
const {return std::hash<int>{}(coords.first)^std::hash<int>{}(coords.second);}
};

class SimulationEnv {
    public:
    std::unordered_map<std::pair<int,int>,Agent*,hashcoords> positions;
    
    void initprey()
    {
    Agent *preyptr = new Prey();
    positions[std::make_pair(1,2)] = preyptr;
    }

    SimulationEnv(){}
};

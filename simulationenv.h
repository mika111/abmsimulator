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
    int x;
    int y;
    std::random_device seedsource;
    std::default_random_engine genx;
    std::default_random_engine geny;
    std::uniform_int_distribution<int> xgen;
    std::uniform_int_distribution<int> ygen;
    std::unordered_map<std::pair<int,int>,Agent*,hashcoords> positions;
    SimulationEnv(int xin,int yin):x(xin),y(yin),genx(seedsource()),geny(seedsource()),xgen(1,x),ygen(1,y){}

    std::pair<int,int> genrandcoord()
    {
        return std::make_pair(xgen(genx),ygen(geny));
    }
    template<typename Arbitraryagent>
    void spawnagents(int numagents)
    {
        for(int i = 0;i<numagents;i++)
        {
        Arbitraryagent *ptr = new Arbitraryagent();    
        positions[genrandcoord()] = ptr;
        }
    }

};

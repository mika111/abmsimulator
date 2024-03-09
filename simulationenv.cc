#pragma once
#include "AgentClass.cc"
#include "preyagent.cc"
#include <random>
#include <unordered_map>
#include <thread>

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
        std::pair<int,int> location = genrandcoord();
        Arbitraryagent *ptr = new Arbitraryagent(location.first,location.second);    
        positions[location] = ptr;
        }
    }
    };

    

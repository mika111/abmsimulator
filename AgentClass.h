#pragma once
#include <random>
#include <unordered_map>
#include <thread>
class Agent {
    public:
    //these are all impossible so i know if its erroring
    int typeofagent = 0;
    int energyv = 0;
    int foodchainv = 0;
    int positionx = - 1;
    int positiony = -1;
    Agent() = default;
    Agent(int agent,int energy,int foodchainpos,int posx,int posy): typeofagent(agent),energyv(energy),foodchainv(foodchainpos),positionx(posx),positiony(posy) {}
    
    virtual int agenttype(){return -1;}
    virtual int energy(){return -1;}
    virtual int foodchain(){return -1;}
    std::pair<int,int> returnposition()
    {return std::make_pair(positionx,positiony);}

    void moveagent(int dx,int dy)
    {
        positionx = positionx + dx;
        positiony = positiony + dy;
    }
    virtual ~Agent(){}
};

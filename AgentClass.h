#pragma once
#include <random>
#include <unordered_map>
#include <thread>
class Agent {
    public:
    //these are all impossible so i know if its erroring
    int typeofagent = -1;
    int energyv = -1;
    int foodchainv = -1;
    int positionx = - 1;
    int positiony = -1;
    Agent() = default;
    Agent(int agent,int energy,int foodchainpos,int posx,int posy): typeofagent(agent),energyv(energy),foodchainv(foodchainpos),positionx(posx),positiony(posy) {}
    
    std::pair<int,int> returnposition()
    {return std::make_pair(positionx,positiony);}
    void moveagent(int dx,int dy)
    {
        positionx = positionx + dx;
        positiony = positiony + dy;
    }
    template <typename ArbitraryAgent>
    std::pair<int,int> eat(ArbitraryAgent* target){
        std::pair coords = std::make_pair(target->positionx,target->positiony);
        delete target;
        return coords;
        //return coords to the simulation env so the simulator can clear the hash table entry related to the object
    }
    virtual ~Agent(){}
};

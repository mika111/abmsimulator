#pragma once
#include <random>
#include <unordered_map>
#include <thread>
#include <unordered_map>

struct hashcoords {
//hash function so i can use a hash map for the coordinates of the agents
std::size_t operator()(const std::pair<int,int> &coords) 
const {return std::hash<int>{}(coords.first)^std::hash<int>{}(coords.second);}
};

class Agent {
    public:
    //these are all impossible so i know if its erroring
    int typeofagent = -1;
    int energyv = -1;
    int foodchainv = -1;
    int positionx = - 1;
    int positiony = -1;
    std::unordered_map<int,int> *ref;
    std::unordered_map<std::pair<int,int>,Agent*,hashcoords>* home; /*pointer to home (hash map) 
    so agent can interact with its environment autonomously */

    Agent() = default;
    Agent(int agent,int energy,int foodchainpos,int posx,int posy,std::unordered_map<int,int> &ref): typeofagent(agent),energyv(energy),foodchainv(foodchainpos),positionx(posx),positiony(posy),ref(&ref) {}
    
    void checkcollisions()
    {
        //check if theres anyone to eat or breed with

    }

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

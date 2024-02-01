#pragma once
#include "AgentClass.h"

class Prey: public Agent {
    public:
    Prey(int posx,int posy):Agent(1,100,1,posx,posy){}
    int agenttype() override {return typeofagent;}
    int energy() override {return energyv;}
    int foodchain() override {return foodchainv;}
    //pair<int,int> position() override{return std::make_pair(positionx,positiony);}
};
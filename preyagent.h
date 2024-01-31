#pragma once
#include "AgentClass.h"


class Prey: public Agent {
    public:
    int typeofagent = 1;
    int energyv = 100;
    int foodchainv = 1;
    int agenttype() override {return typeofagent;}
    int energy() override {return energyv;}
    int foodchain() override {return foodchainv;}
    Prey(){}
    ~Prey();

};
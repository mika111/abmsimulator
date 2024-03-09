#pragma once
#include "AgentClass.cc"

class Prey: public Agent {
    public:
    Prey(int posx,int posy,std::unordered_map<int,int>&home):Agent(1,100,1,posx,posy,home){}
};
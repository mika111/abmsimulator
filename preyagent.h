#pragma once
#include "AgentClass.h"

class Prey: public Agent {
    public:
    Prey(int posx,int posy):Agent(1,100,1,posx,posy){}
    
};
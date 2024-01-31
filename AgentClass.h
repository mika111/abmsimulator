#pragma once
class Agent {
    public:
    virtual int agenttype(){return -1;}
    virtual int energy(){return -1;}
    virtual int foodchain(){return -1;}
};

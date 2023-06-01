#pragma once

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "map.h"
#include "robot.h"


class Humanic : public Robot
{
    friend class map;
    public:
        Humanic();/*no param constructor*/
        Humanic(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y);
        /*constructor for humanic class and it's base class*/
        virtual int getDamage() override;/*overriding getdamage function of Robot Class*/
};


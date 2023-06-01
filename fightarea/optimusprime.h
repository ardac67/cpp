#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "map.h"
#include "robot.h"
#include "humanic.h"


class OptimusPrime : public Humanic
{
    friend class map;
    public:
        OptimusPrime();/*default const*/
        OptimusPrime(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y);
        /*parametrized conts*/
        std::string getType() override;/*overrides getTtype for base class returns type*/
        int getDamage() override;/*overrides for base class return int as damage*/
        void takenDamage(int damage);/*decrements damage*/
        int returnHitPoints();/*returns just health*/

};



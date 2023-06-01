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


class Robocop : public Humanic
{
    friend class map;
    public:
        Robocop();/*default const*/
        Robocop(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y); /*parametrized conts*/
        std::string getType();/*overrides getTtype for base class returns type*/
        int getDamage() override;/*overrides for base class return int as damage*/
        void takenDamage(int damage);/*decrements damage*/
        int returnHitPoints();/*returns just health*/

};


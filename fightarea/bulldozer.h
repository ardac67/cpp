#pragma once

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "map.h"
#include "robot.h"


class Bulldozer : public Robot
{
    friend class Map;
    public:
        Bulldozer();/*default constructor no param*/
        Bulldozer(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y);/*parametrized constructor*/
        std::string getType() override;/*overriding base class getType function*/
        int getDamage() override;/*overriding getDamage base class function*/
        void takenDamage(int damage);/*just decrease the health*/
        int returnHitPoints(){/*just returns the health*/
            return hitPoints;
        }

};


#pragma once
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "map.h"
#include "robot.h"



class Roomba : public Robot
{
    friend class Map;
    public:
        Roomba();/*no param const*/
        Roomba(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y);
        /*parametrized constructor*/
        std::string getType() override;/*overriding for getType*/
        int getDamage() override;/*overriding for getDamage*/
        void takenDamage(int damage);/*returns taken damage*/
        int returnHitPoints(){/*returns health points*/
            return hitPoints;
        }

};

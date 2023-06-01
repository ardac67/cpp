#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "roomba.h"



Roomba::Roomba():Robot(){}
/*no param const*/
Roomba::Roomba(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y):
            Robot(map,newType,newStrenght,newHit,name,x,y){}
/*parametrized constructor*/
std::string Roomba::getType(){/*overriding for getType*/
    return "roomba";
}            

int Roomba::getDamage(){/*overriding for getDamage*/
    return (Robot::getDamage()+Robot::getDamage());/*doubling damage according to instructions*/
}

void Roomba::takenDamage(int damage){/*returns taken damage*/
    hitPoints=hitPoints-damage;
}

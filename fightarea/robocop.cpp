#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "robocop.h"


Robocop::Robocop():Humanic(){}
/*no param constuctor*/
Robocop::Robocop(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y):
            Humanic(map,newType,newStrenght,newHit,name,x,y){}
/*with param cons for humanic class constructs and the for the robocop class*/    

std::string Robocop::getType(){/*just returns the type*/
    return "robocop";
}            

int Robocop::getDamage(){/*get damage for humanic object first*/
    return Humanic::getDamage();
}

void Robocop::takenDamage(int damage){/*just decrements the health according to the taken damage*/
    hitPoints=hitPoints-damage;
}

int Robocop::returnHitPoints(){/*just returns healht points*/
    return hitPoints;
}

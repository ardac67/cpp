#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "humanic.h"

Humanic::Humanic():Robot(){}

Humanic::Humanic(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y):
            Robot(map,newType,newStrenght,newHit,name,x,y){}/*constructs the robot class and humanic class*/

int Humanic::getDamage(){
    int damage1=Robot::getDamage();/*calls robot getdamage first then with luck add +50 points for tactical nuke for 
    humanic objects*/
    if(rand() %10 ==0){/*calculating luck*/
        std::cout << getName() <<  " attacks for (Tactical Nuke) " << 
        50 << " points!!" << std::endl;
        damage1+=50;
    }
    return damage1;
}
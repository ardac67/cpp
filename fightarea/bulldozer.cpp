#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "bulldozer.h"


Bulldozer::Bulldozer():Robot(){}

Bulldozer::Bulldozer(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y):
            Robot(map,newType,newStrenght,newHit,name,x,y){} /*constructor for inherited class*/

std::string Bulldozer::getType(){
    return "bulldozer";/*just returning it's type*/
}            

int Bulldozer::getDamage(){
    return Robot::getDamage();/*calls inherited getdamage function*/
}  

void Bulldozer::takenDamage(int damage){
    hitPoints=hitPoints-damage;/*calculates the health*/
}

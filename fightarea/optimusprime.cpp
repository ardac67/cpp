#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "optimusprime.h"



OptimusPrime::OptimusPrime():Humanic(){}
/*no param constuctor*/
OptimusPrime::OptimusPrime(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y):
            Humanic(map,newType,newStrenght,newHit,name,x,y){}
/*with param cons for humanic class constructs and the for the optimus prime class*/            

std::string OptimusPrime::getType(){/*just returns the type*/
    return "optimusprime";
}            

int OptimusPrime::getDamage(){/*get damage for humanic object first then calculate the optimus ulti luck then multiply 
the damage by two */
    int damage2=Humanic::getDamage();
    int optimusUlti1=(rand() % 100) +1;
    if(optimusUlti1<=15 && optimusUlti1>0){
        std::cout << getName() <<  " attacks for (Optimus Ulti) " << 
        (damage2=damage2*2) << " points!!" << std::endl;
    }
    return damage2; 
}

void OptimusPrime::takenDamage(int damage){
    hitPoints=hitPoints-damage;/*just decrements the health according to the taken damage*/
}

int OptimusPrime::returnHitPoints(){
    return hitPoints;/*just returns healht points*/
}

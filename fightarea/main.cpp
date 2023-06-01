#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "map.h"
#include "robot.h"
#include "humanic.h"
#include "roomba.h"
#include "optimusprime.h"
#include "robocop.h"
#include "bulldozer.h"

int main(){
    std::string s;
    srand(time(NULL));
    Map w;
    
    int roombaCount = 0;
    while(roombaCount < 5){/*creating roomba object as 5*/
        int x = rand() % MAPSIZE;/*defining respawn place*/
        int y = rand() % MAPSIZE;/*defining respawn place*/
        if(w.getAt(x, y) == NULL){
            std::string name="Roomba";
            std::string unified=name+"_"+std::to_string(roombaCount);
            Roomba* r1 = new Roomba(&w,2,3,10,unified, x, y);/*creating objects of roomba*/
            roombaCount++;
        }
    }  
    
   
    int bulldozerCount = 0;
    while(bulldozerCount < 5){/*creating bulldozer objects as 5*/
        int x = rand() % MAPSIZE;/*defining respawn place*/
        int y = rand() % MAPSIZE;/*defining respawn place*/
        if(w.getAt(x, y) == NULL){
            std::string name="Bulldozer";
            Bulldozer* bd1 = new Bulldozer(&w,3,50,200,name+"_"+std::to_string(bulldozerCount), x, y);
            /*creating objects of bulldozer*/
            bulldozerCount++;
        }
    }  
    
    int optimusCount = 0;
    while(optimusCount < 5){/**creating optimus objects as 5*/
        int x = rand() % MAPSIZE;/*defining respawn place*/
        int y = rand() % MAPSIZE;/*defining respawn place*/
        if(w.getAt(x, y) == NULL){
            std::string name="Optimus";
            OptimusPrime* pr1 = new OptimusPrime(&w,0,100,100,name+"_"+std::to_string(optimusCount), x, y);
             /*creating objects of optimus prime*/
            optimusCount++;
        }
    }
    
    int robocopCount = 0;
    while(robocopCount < 5){/**creating robocop objects as 5*/
        int x = rand() % MAPSIZE;/*defining respawn place*/
        int y = rand() % MAPSIZE;/*defining respawn place*/
        if(w.getAt(x, y) == NULL){
            std::string name="Robocop";
            Robocop* r1 = new Robocop(&w,1,30,40,name+"_"+std::to_string(robocopCount), x, y);
            /*creating robocop objects*/
            robocopCount++;
        }
    }  
    while(w.getSurvivors()>1){/*simulate until one of them survive*/
        //w.Display();
        w.SimulateOneStep();/*move until fight some robot*/
    }   

    return 0;

}
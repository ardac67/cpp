#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "map.h"
#include "robot.h"



Robot::Robot(){/*assignin default constructor values*/
    map = NULL;
    moved = false;
    x = 0;
    y = 0;
}

Robot::Robot(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y){
    /*filling protected members with constructor parameters*/
    this->map = map;
    moved = false;
    this->x = x;
    this->y = y;
    type=newType;
    strenght=newStrenght;
    hitPoints=newHit;
    this->name=name;
    map->setAt(x, y, this);/*setting map placement of object*/
}

Robot::~Robot(){}

int Robot::getDamage(){/*returning base damage all robot objects*/
   int damage=(rand() % strenght) +1;
   std::cout << getType() 
              <<  " Attacks for " << damage    
              << " points!!" << std::endl;
   return damage;
}
/*printing hit message in fight between r1 and r2 robots and takes damage function for the print statements*/
void Robot::hitMessage(Robot *r1,Robot *r2,int damage){
    std::cout << r1->name <<"(" << r1->hitPoints << ") "<< " hits "
    << r2->name<< "("<<(r2->hitPoints+damage)<< ")"
    <<" with " << damage << std::endl;
    if(r2->hitPoints<=0){
        std::cout << "The new hitpoints of "<< r2->name << " is " << 0 << std::endl;
    }
    else{
        std::cout << "The new hitpoints of "<< r2->name << " is " << r2->hitPoints << std::endl;
    }
    
}
/*returns name*/
std::string Robot::getName(){
    return name;
}
/*moves the robot until one hit*/
void Robot::move(){

    bool hitSomebody=false;
    bool goIntoLoop=true;
    if(map->getSurvivors()<2){
        goIntoLoop=false;/*if it is 1 survivor just skip loop*/
    }
    while(!hitSomebody && goIntoLoop){/*if you are hit somebody just break from loop*/
        int dir = rand() % 4;/*getting direction*/
        if (dir==0) {
            if ((y>0) && (map->getAt(x,y-1)==NULL))/*if nobody there ,move */
            {
                map->setAt(x,y-1,map->getAt(x,y));/*move to the next place*/
                map->setAt(x,y,NULL);  /*set null for old place*/
                y--;
            }
            else if((y>0) && (map->getAt(x,y-1)!=NULL))
            {   /*if somebody there fight with it until one of them is death*/
                while(this->hitPoints>=0 && map->getAt(x,y-1)->returnHitPoints()>=0)
                {   
                    hitSomebody=true;/*for breaking loop*/
                    int damage=this->getDamage();/*returns damage for appropriate type*/
                    map->getAt(x,y-1)->takenDamage(damage);/*just decrements the damage*/
                    map->getAt(x,y)->hitMessage(map->getAt(x,y),map->getAt(x,y-1),damage);/*prints the message*/
                    if(map->getAt(x,y-1)->returnHitPoints()<=0)
                    {       /*if it is dead delete it then move the the robot that first hits*/
                            delete (map->grid[x][y-1]);
                            map->setAt(x,y-1,this);
                            map->setAt(x,y,NULL);
                            y--;
                            break;
                    }
                    int givenDamage=map->getAt(x,y-1)->getDamage();
                    map->getAt(x,y)->takenDamage( givenDamage );
                    map->getAt(x,y)->hitMessage(map->getAt(x,y-1),map->getAt(x,y),givenDamage);
                    if(map->getAt(x,y)->returnHitPoints()<=0)
                    {   
                        /*if it is dead delete it then dont' move the the robot that second hits*/
                            delete (map->grid[x][y]);
                            map->setAt(x,y,NULL); 
                            break;
                    }
                }
            }
        }

        else if (dir==1){
            if ((y<MAPSIZE-1) && (map->getAt(x,y+1)==NULL)){
                map->setAt(x,y+1,map->getAt(x,y));
                map->setAt(x,y,NULL);
                y++;
            }
            else if((y<MAPSIZE-1) && (map->getAt(x,y+1)!=NULL))
            {
                while(this->hitPoints>=0 && map->getAt(x,y+1)->returnHitPoints()>=0)
                {   
                    hitSomebody=true;
                    int damage=this->getDamage();
                    map->getAt(x,y+1)->takenDamage(damage);
                    map->getAt(x,y)->hitMessage(map->getAt(x,y),map->getAt(x,y+1),damage);
                    if(map->getAt(x,y+1)->returnHitPoints()<=0)
                    {
                            delete (map->grid[x][y+1]);
                            map->setAt(x,y+1,this);
                            map->setAt(x,y,NULL);
                            y++;
                            break;  
                    }
                    int givenDamage=map->getAt(x,y+1)->getDamage();
                    map->getAt(x,y)->takenDamage( givenDamage );
                    map->getAt(x,y)->hitMessage(map->getAt(x,y+1),map->getAt(x,y),givenDamage);
                    if(map->getAt(x,y)->returnHitPoints()<=0)
                    {
                            delete (map->grid[x][y]);
                            map->setAt(x,y,NULL);
                            break;
                    }
                }
            }        
        }

            else if (dir==2){
                if ((x>0) && (map->getAt(x-1,y)==NULL)){
                    map->setAt(x-1,y,map->getAt(x,y));  
                    map->setAt(x,y,NULL);  
                    x--;
                }
                else if((x>0) && (map->getAt(x-1,y)!=NULL))
                {
                    while(this->hitPoints>=0 && map->getAt(x-1,y)->returnHitPoints()>=0)
                    {
                        hitSomebody=true;
                        int damage=this->getDamage();
                        map->getAt(x-1,y)->takenDamage(damage);
                        map->getAt(x,y)->hitMessage(map->getAt(x,y),map->getAt(x-1,y),damage);
                        if(map->getAt(x-1,y)->returnHitPoints()<=0)
                        {
                               delete (map->grid[x-1][y]);
                                map->setAt(x-1,y,this);
                                map->setAt(x,y,NULL);
                                x--; 
                                break;
                        }
                        int givenDamage=map->getAt(x-1,y)->getDamage();
                        map->getAt(x,y)->takenDamage( givenDamage);
                        map->getAt(x,y)->hitMessage(map->getAt(x-1,y),map->getAt(x,y),givenDamage);
                        if(map->getAt(x,y)->returnHitPoints()<=0)
                            {
                                delete (map->grid[x][y]);
                                map->setAt(x,y,NULL);
                                break;
                            }
                    }
                }
            }

            else if(dir==3){
                if ((x<MAPSIZE-1) && (map->getAt(x+1,y)==NULL)){
                    map->setAt(x+1,y,map->getAt(x,y));  
                    map->setAt(x,y,NULL); 
                    x++;
                }
                else if((x<MAPSIZE-1) && (map->getAt(x+1,y)!=NULL) )
                {
                    while(this->hitPoints>=0 && map->getAt(x+1,y)->returnHitPoints()>=0)
                    {
                        hitSomebody=true;
                        int damage=this->getDamage();
                        map->getAt(x+1,y)->takenDamage(damage);
                        map->getAt(x,y)->hitMessage(map->getAt(x,y),map->getAt(x+1,y),damage);
                        if(map->getAt(x+1,y)->returnHitPoints()<=0)
                        {
                               delete (map->grid[x+1][y]);
                                map->setAt(x+1,y,this);
                                map->setAt(x,y,NULL);
                                x++; 
                                break;
                        }
                        int givenDamage=map->getAt(x+1,y)->getDamage();
                        map->getAt(x,y)->takenDamage( givenDamage );
                        map->getAt(x,y)->hitMessage(map->getAt(x+1,y),map->getAt(x,y),givenDamage);
                        if(map->getAt(x,y)->returnHitPoints()<=0)
                        {
                                delete (map->grid[x][y]);
                                map->setAt(x,y,NULL); 
                                break;
                        }
                    }
                }
            }
    }
}

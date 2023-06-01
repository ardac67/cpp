#pragma once

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "map.h"

class Robot
{   
    friend class Map;
    public:
        Robot();/*no param const*/
        Robot(Map* map ,int newType,int newStrenght,int newHit,std::string name,int x,int y);
        /*parametrized constructor*/
        ~Robot();/*destructor*/
        std::string getName();/*returns name*/
        virtual std::string getType()=0;/*virtual function for getType*/
        virtual int getDamage();/*getDamage virtual function*/
        void move();/*member function for all robots*/
        virtual void takenDamage(int damage)=0;/*virtual function for taken damage takes damage int damage param*/
        virtual int returnHitPoints()=0;/*returns just health*/
        void hitMessage(Robot *r1,Robot *r2,int damage);/*printing hitmessage with r1(hitter) r2(taker) and damage parameters*/
    protected:
        std::string name;
        int type;
        int  strenght;
        int hitPoints;
        int x,y;/*just for the placement in map*/
        bool moved;/*understanding if it is moved*/
        Map * map;    
};



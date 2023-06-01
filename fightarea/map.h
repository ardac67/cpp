#pragma once

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

const int MAPSIZE=10;

class Robot;
class Bulldozer;
class Roomba;
class Humanic;
class OptimusPrime;
class Robocop;

class Map{
    
    friend class Robot;
    friend class Bulldozer;
    friend class Roomba;


    public:
        Map();/*no param constructor*/
        ~Map();/*destructor*/
        Robot* getAt(int x, int y);/*getting object in that grid*/
        void setAt(int x, int y, Robot *org);/*setting object of that grid*/
        void Display();/*displaying for the grid for just debug*/
        void SimulateOneStep();/*it is not just simulates for one step it is simulates for just for hit*/
        int getSurvivors();/*returns the alive robot's count*/

    private:
        Robot* grid[MAPSIZE][MAPSIZE];/*2d array for grid*/
};


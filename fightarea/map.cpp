#include <cstddef>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "map.h"
#include "robot.h"

Map::Map(){
    int i,j;
    for(i = 0; i < MAPSIZE; i++){
        for(j = 0; j < MAPSIZE; j++){
            grid[i][j] = NULL;/*creating map for fight */
        }
    }
}

Map::~Map(){
    int i,j;
    for(i = 0; i < MAPSIZE; i++){
        for(j = 0; j < MAPSIZE; j++){
            if(grid[i][j] != NULL) delete grid[i][j];/*destructor for map object*/
        }
    }
}


Robot* Map::getAt(int x, int y){/*returning grid ingredients*/
    if(x >= 0 && (x < MAPSIZE) && y >= 0 && (y<MAPSIZE))/*edge conditions*/
        return grid[x][y];  

    return NULL;
}

void Map::setAt(int x, int y, Robot *org)/*assigning grid index to a robot*/
{
    if ((x>=0) && (x<MAPSIZE) && (y>=0) && (y<MAPSIZE))/*edge conditions*/
    {
        grid[x][y] = org;
    }   
}

void Map::Display(){/*just for the debugging purpose printing robot's place*/
/*     int i,j;
    std::cout << std::endl << std::endl;

    for(j = 0; j<MAPSIZE; j++){
        for(i = 0; i < MAPSIZE; i++){
            if(grid[i][j] == NULL) std::cout << ".";
            else if(grid[i][j]->getType() == 0) std::cout << "O";
            else if(grid[i][j]->getType() == 1) std::cout << "R";
            else if(grid[i][j]->getType() == 2) std::cout << "a";
            else if(grid[i][j]->getType() == 3) std::cout << "B";
        }
        std::cout << std::endl;
    } */
}


void Map::SimulateOneStep(){/*moving robots if it is not moved*/
    int i, j;

    for(i = 0; i < MAPSIZE; i++){/*set all robots as not moved*/
        for(j = 0; j < MAPSIZE; j++){
            if(grid[i][j] != NULL) grid[i][j]->moved = false;
        }
    }
    //testcode
    for(i = 0; i < MAPSIZE; i++){/*then if they are not moved moved it according to the indexes*/
        for(j = 0; j < MAPSIZE; j++){
            if(grid[i][j] != NULL){
                if(grid[i][j]->moved == false){
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }
    }

}
int Map::getSurvivors(){/*returns just survivor count*/
    int i,j,count=0;
    for(i = 0; i < MAPSIZE; i++){
        for(j = 0; j < MAPSIZE; j++){
            if(grid[i][j] != NULL) count++;/*increment count if it is not null which means there are robots there*/
        }
    }
    return count;
}



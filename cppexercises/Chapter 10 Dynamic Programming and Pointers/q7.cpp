#include <iostream>

using namespace std;

class Player{
    public: 
        Player(){};
        Player(string Name,int Score){
            name=Name;
            score=Score;
        }
        string Name(){
            return name;
        }
    private:
        string name;
        int score;
};
Player * addPlayer(Player &player,int &size,Player * playerArr);
Player * removePlayer(Player &playerToAdd,int &currentSize,Player *currentPlayerarray,string toDelete);
int main(){
    Player * playerArray;
    int currentSize=0;
    playerArray = new Player[currentSize];
    /*empty list of Player object*/
    /*adding players*/
    Player p1("arda",90) ,p2("Anil",100), p3("Naide", 90);
    
    playerArray=addPlayer(p1,currentSize,playerArray);
    playerArray=addPlayer(p2,currentSize,playerArray);
    playerArray=addPlayer(p3,currentSize,playerArray);

    for(int i=0;i<3;i++){
        cout << playerArray[i].Name() << endl;
    }
    playerArray=removePlayer(p3,currentSize,playerArray,"Naide");
    for(int i=0;i<3;i++){
        cout << playerArray[i].Name() << endl;
    }

}

Player * addPlayer(Player &playerToAdd,int &currentSize,Player *currentPlayerarray){
    currentSize=currentSize+1;
    Player * playerarrnew;
    playerarrnew = new Player[currentSize];
    for(int i=0;i<currentSize-1;i++){
        playerarrnew[i]=currentPlayerarray[i];
    }
    playerarrnew[currentSize-1]=playerToAdd;
    delete [] currentPlayerarray;
    return playerarrnew;
}
Player * removePlayer(Player &playerToAdd,int &currentSize,Player *currentPlayerarray,string toDelete){
    currentSize=currentSize-1;
    Player * playerarrnew;
    playerarrnew = new Player[currentSize];
    int k=0;
    int state=0;
    while(k<currentSize){
        if(currentPlayerarray[k].Name()==toDelete){
            state=1;
            continue;
        }
        if(state==1){
            playerarrnew[k]=currentPlayerarray[k+1];
            k++;
        }
        else 
            {
                playerarrnew[k]=currentPlayerarray[k];
                k++;
            }    


            

    }
    delete [] currentPlayerarray;
    return playerarrnew;
}

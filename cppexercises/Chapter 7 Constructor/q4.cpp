#include <iostream> 

using namespace std;

class hotDogStand{
    public:
    hotDogStand(int id,int sold){
        standId=id;
        hotDogSold=sold;
        TotalSum+=hotDogSold;
    }
    void justSold(){
        hotDogSold++;
        TotalSum++;
    }
    int returnDogSold(){
        return hotDogSold;
    }
    static int ReturnTotal(){
        return TotalSum;
    }
    private :
    int standId;
    int hotDogSold;
    static int TotalSum;
};
int hotDogStand::TotalSum=0;
int main(){

    hotDogStand stand1(1,0);
    hotDogStand stand2(2,4);
    hotDogStand stand3(3,4);
    cout << stand1.ReturnTotal() << endl;
    stand2.justSold();
    stand3.justSold();
    cout << stand3.ReturnTotal() << endl;
}
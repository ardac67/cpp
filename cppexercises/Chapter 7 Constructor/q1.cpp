#include <iostream> 

using namespace std;



class Month{
    public:
        Month(string input){
            string months[4]={"Jan","Feb","March","April"};
            for(int i=0;i<4;i++){
                if(months[i]==input){
                    month=i+1;
                }
            }
        }
        Month(int input){
            month=input;
        }
        int returnMonth(){return month;};
        int returnNextMonth(){
            if(month+1>4)
                return 1;
            else 
                return month+1;    
        }
    private:
        int month;
};

int main(){
    Month month("March");
    cout << month.returnMonth()<< endl;
    cout << month.returnNextMonth()<< endl;
}
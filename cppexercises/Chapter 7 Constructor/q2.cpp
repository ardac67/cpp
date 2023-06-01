#include <iostream> 

using namespace std;

class Month{
    public:
        Month(string input){
            string months[4]={"Jan","Feb","March","April"};
            for(int i=0;i<4;i++){
                if(months[i]==input){
                    month=months[i];
                }
            }
        }
        Month(int input){
            month=input;
        }
        string returnMonth(){return month;};
        string returnNextMonth(){
            string returnValue;
           string months[4]={"Jan","Feb","March","April"};
            for(int i=0;i<4;i++){
                if(months[i]==month){
                    if(i+1<4){
                         returnValue=months[i+1];
                    }
                    else 
                        returnValue=months[0];
                }
            }
            return returnValue;   
        }
    private:
        string month;
};

int main(){
    Month month("Jan");
    cout << month.returnMonth()<< endl;
    cout << month.returnNextMonth()<< endl;
}
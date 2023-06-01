#include <iostream> 
#include <vector>
using namespace std;

class Suitor{

    public:
       Suitor(){
            suitors={1,2,3,4,5,6};
            int count=1;
            for(int i=0;i<suitors.size();i++){
                if(count==3){
                    suitors.erase(suitors.begin()+i);
                    count=1;
                    if(i+1>=suitors.size()){
                        i=0;
                        count=2;
                    }
                }
                if(suitors.size()==1)
                    break;
                count++;
            }
            for(int i=0;i<suitors.size();i++){
                cout << suitors[i];
            }
           
       } 
    private:
        vector<int> suitors;
};

int main(){
    Suitor sui;
}
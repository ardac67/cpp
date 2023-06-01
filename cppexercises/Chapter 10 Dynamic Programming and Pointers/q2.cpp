#include <iostream>
#include <cstdlib>

using namespace std;

class Poly{
    public:
        Poly(){};
        Poly(int _degree){
            degree=_degree;
            coefficient = new int [degree];
            for(int i=0;i<degree;i++)
                cin >> coefficient[i];
        };
        void printPoly(){
            
            for(int i=0;i<degree;i++){
                for(int j=0;j<coefficient[i];j++){
                    if(j!=coefficient[i]-1){
                        cout << coefficient[i];
                        cout << "x*" ;
                    }
                    else
                        cout << "x";
                    
                }
                if(i!=degree-1){
                    cout <<"+";
                }
                else 
                    cout << " ";
            }
        }
        
    private:
        int degree;
        int *coefficient;
};
int main(){

    Poly pol(3);
    pol.printPoly();
}
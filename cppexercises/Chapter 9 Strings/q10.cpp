#include <iostream>
#include <cstdlib>
using namespace std;


class Trivia{
    public:
    Trivia(){
        questions= new string*;
        for(int i=0;i<3;i++){
            questions[i] = new string;
        }
        questions[0][0]={"Arda kimdir","Arda"};
        questions[1][0]={"Arda Çaltepe","Çaltepe"};
        questions[2][0]={"Takim nedir","GS"};
        string answer;
        int money=0;
        for(int i=0;i<3;i++){
            cout << questions[i][0] << endl;
            cin >> answer;
            if(answer==questions[i][0]){
                money=money+1;
                cout << "Answer is correct!!" << endl;
            }
            else    
                cout << "False" << endl;
        }
    }
    private:
        string **questions;
};

int main(){
    Trivia trivia;
}
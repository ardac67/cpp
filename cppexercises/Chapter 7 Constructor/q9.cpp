#include <iostream>
#include <string>
#include<time.h>
#include <vector>

using namespace std;

class PostalService 
{   
    public:
        PostalService(string _number );
        string returnAsString();
    private:
        string number;
};

int main()
{   
  
    PostalService posta("110100101000101011000010011");
    posta.returnAsString();


}

PostalService::PostalService(string _number )
{
    number=_number;
}
string PostalService::returnAsString(){
    int i=0;
    int summation=0;
    vector <string> stringArray;
    int formatArray[6]={0,7,4,2,1,0};
    while(number[i]!='\0'){
        if(i==0){
            i++;
            continue;
        }  
        else{
            if(i==27)
                break; 
            else{
                if(i%5==0){
                    int num=number[i]-'0';
                    summation=summation+(num*formatArray[5]);
                    cout << "Number pushed"<< endl ;
                    stringArray.push_back(to_string(summation));
                    summation=0;
                    i++;
                }
                else {
                    int num=number[i]-'0';
                    //cout << "Number agregaret!! "<< endl;
                    summation=summation+(num*formatArray[i%5]);
                    i++;
                }
            }    
        }    
       
    }
    for(int i=0;i<stringArray.size();i++)
        cout << stringArray[i];
}

#include <iostream>
#include <vector>
using namespace std;

class AddOddeven{
    public:
        AddOddeven(){}

        AddOddeven & operator += (int toAdd){
            int sum;
            if(toAdd%2==0){
                if(even.size()==0){
                    even.resize(1);
                    even[0]=toAdd;
                     printf("Added\n");
                }
                else{
                     even.push_back(toAdd);
                }   

                 
            }
            else {
                if(odd.size()==0){
                    odd.resize(1);
                    odd[0]=toAdd;
                }
                else
                    odd.push_back(toAdd);    
            }   
            return *this;  

        }
        friend ostream & operator << (ostream & str,AddOddeven obj){
            int oddSum=0,evenSum=0;
            for(int i=0;i<obj.even.size();i++){
                evenSum=evenSum+obj.even[i];
            }
            str << evenSum << ", Ortalama:-> " <<  evenSum/obj.even.size() << endl;
            for(int i=0;i<obj.even.size();i++){
                str <<obj.even[i] << " "; 
            }

            return str;
        }
    private:
        vector<int> odd;
        vector <int> even;
};

int main(){
    AddOddeven obj;
    obj+=6;
    obj+=4;
    (obj+=6)+=8;
    cout << obj << endl;

}
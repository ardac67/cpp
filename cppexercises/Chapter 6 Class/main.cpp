#include <iostream>
#include <string>
#include<time.h>
#include <vector>

using namespace std;
class BoxOfProduce
{
    private :
        vector<string> boxofStuff;
    public:
        void set(string stuff);
        void get();  
        void set(int index,string replacement);
        void output();  
};

int main()
{   
    BoxOfProduce produced;
    string Package[5]={"Broccoli","Tomato","Kiwi","Kale","Tomatillo"};
    srand(time(0));
    for(int i=0;i<3;i++)
    {   
        int number= (rand() % 5);
        produced.set(Package[number]);
    }
    int x=0;
    int indexObject,indexExists;
    do
    {   
        
        cout << "Package contents!!" << endl;
        for(int i=0;i<5;i++)
            cout << Package[i] << " " << i << endl;
        cout << "Object contents!!" << endl;
        produced.get();
        cout <<"Press -1 to quit " << endl;
        cin >> x;
        if(x==-1)
            break;   
        cout << "Enter the vegatables you wanne change " << endl;
        cin>>  indexObject >> indexExists;
        produced.set(indexObject,Package[indexExists]);

    } while (1);
    


}

void BoxOfProduce::set(string stuff)
{
    boxofStuff.push_back(stuff);
}
void BoxOfProduce::set(int index,string replacement)
{
    boxofStuff[index]=replacement;
}
void BoxOfProduce::get()
{   
     for(int i=0;i<3;i++)
            cout << boxofStuff[i] << " " << i << endl;

}
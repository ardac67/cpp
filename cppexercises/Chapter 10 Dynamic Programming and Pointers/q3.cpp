#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;


class Cstring{

    public:
        Cstring(){
            cString = new char[10];
            cin >> cString;
            int size=0;
            for(int i=0;cString[i]!='\0';i++)
                size++;
            //printf("%d",size);    
            char * headptr,*tailptr;
            headptr=&cString[0];
            tailptr=&cString[size-1];    
            //printf("%c %c",*headptr,*tailptr);
            for(int i=0;size/2;i++){
                if(!(headptr<tailptr))
                    break;
                else
                {
                    char temp=*headptr;
                    *headptr=*tailptr;
                    *tailptr=temp;
                }
                headptr++;
                tailptr--;
                   
            }
            for(int i=0;cString[i]!='\0';i++)
            printf("%c",cString[i]);
        }   
    private :
        char * cString;
};

int main(){

    Cstring cc;

}

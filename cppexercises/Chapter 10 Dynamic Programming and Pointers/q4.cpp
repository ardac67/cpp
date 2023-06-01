/*
    studentClass
 *  string name
 * int numClass the track how many courses student enrolled
 * dynamicarray string used to store names of classes student enrolled
 * 
 */

#include <iostream>

using namespace std;

class Student{

    public:
    Student(){
        cout << "Enter the name "<< endl;
        cin >> studentName;
        cout << "Enter the classCount" << endl;
        cin >> numClasses;
        classList = new string[numClasses];
        cout << "Enter the class you enrolled" << endl;
        for(int i=0;i<numClasses;i++)
            cin >> classList[i];
    }
    void OutputEverything(){
        cout << studentName << endl;
        cout << numClasses << endl;
        for(int i=0;i<numClasses;i++)
            cout << classList[i] << endl;
    }
    void Reset(){
        for(int i=0;i<numClasses;i++)
            classList[i]=" ";
        numClasses=0;
    }
    Student & operator = (const Student &ls){
        numClasses=ls.numClasses;
        //delete [] classList;
        classList = new string[numClasses];
        for(int i=0;i<numClasses;i++)
            classList[i]=ls.classList[i];

        return *this;    
    }
    ~Student(){/*niye 4 oldu xdxdxdxdxd tane çıktıki*/
        printf("Class List deleted\n");
        delete [] classList;

    }
    private:
        string studentName;
        int numClasses;
        string *classList;

};

int main(){
    Student stu;
    stu.OutputEverything();
    Student stu2;
    stu2.OutputEverything();
    (stu=stu2).OutputEverything();
}
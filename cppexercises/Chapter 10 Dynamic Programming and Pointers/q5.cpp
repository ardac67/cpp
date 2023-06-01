/*
 *StudentClass
 *GradeVector to store students grades ->this should be entered until -1
 * use a dynamic array to store histogram
 * then output it

*/
#include <iostream>
#include <vector>
using namespace std;

class Student{
    public:
    Student(){
        int i=0;
        int input=0;
        for(int i=0;i<10;i++){
            studentGrade[i]=1*7+5;
        };
        
       /*  histogramArray = new int*[studentGrade.size()];
        for(int i=0;i<studentGrade.size();i++){
            histogramArray[i]= new int[1];
            printf("a\n");
        } */
   
        

    }
        void PrintHistogram(){
            for(int i=0;i<10;i++){
                cout << histogramArray[i][0] << " " << histogramArray[i][1] << endl; 
            }
        }
    private:
        vector<int> studentGrade;
        int ** histogramArray;
};

int main(){
    Student stu;
    //stu.PrintHistogram();
}
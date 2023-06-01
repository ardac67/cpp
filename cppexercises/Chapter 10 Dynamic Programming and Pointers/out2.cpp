#include <iostream>

using namespace std;

class Student{

    public:
    Student(){}
    Student(string n,int a): name(n) , age(a){}
    friend ostream & operator << (ostream &str,Student &stu);
    string GetName() const{
        return name;
    }
    void SetName(string Name){
        name=Name;
    }
    int getAge() const{
        return age;
    }
    void SetAge(int Age){
        age=Age;    
    }
    bool operator == (Student &ls);
    bool operator != (Student &ls);
    private :
        string name;
        int age;
};
ostream & operator << (ostream &str,Student &stu){
    str << stu.name << " " << stu.age << endl;
    return str;
}
class Course{
    public:
        Course(){
            courseName=" ";
            maxCap=0;
        }
        Course(string n,int c):courseName(n),maxCap(c){
            students= new Student[maxCap];
        }
        Course(string n,Student* stu,int numberOfStu){
            courseName=n;
            maxCap=numberOfStu;
            students = new Student[maxCap];
            for(int i=0;i<numberOfStu;i++){
                students[i].SetName(stu[i].GetName());
                students[i].SetAge(stu[i].getAge());
            }
        }
        friend ostream & operator << (ostream &str,Course & courseToPrint); 
        Student  operator [] (int index) const{
            return students[index];
        }
        Course & operator += (Student &stu){
            bool isInside=false;
            for(int i=0;i<maxCap;i++){
                if( (students[i].GetName()==stu.GetName()) && (students[i].getAge()== stu.getAge()) ){
                    isInside=true;
                    break;
                }
            }
            if(!isInside){
                Student *  newStudents = new Student[maxCap+1];
                for(int i=0;i<maxCap;i++){
                    newStudents[i]=students[i];
                }
                newStudents[maxCap]=stu;
                delete [] students;
                maxCap=maxCap+1;
                students = new Student[maxCap];
                for(int i=0;i<maxCap;i++) {
                    students[i]=newStudents[i];
                }
                delete [] newStudents;
                return *this;
            }
            else 
                return *this;
        }
    private:
    string courseName;
    int maxCap;
    Student * students;
};
ostream & operator << (ostream &str,Course & courseToPrint){
    str << courseToPrint.courseName << " " << courseToPrint.maxCap << endl;
    for(int i=0;i<courseToPrint.maxCap;i++){
        str << courseToPrint.students[i].GetName() << " " <<  courseToPrint.students[i].getAge() << endl;
    }
    return str;
}

bool Student::operator == (Student &ls){
    return (this->age==ls.age) && (this->name==ls.name);
}
bool Student::operator != (Student &ls){
    return (this->age!=ls.age) || (this->name!=ls.name);
}


int main(){
    Student stu1("Arda",25);
    Student stu2("Anil",27);
    Student stu3("Naide",55);
    Student stundetToAdd("Cevdet",66);
    Student stuArray[3]={stu1,stu2,stu3};
    cout << "------Students----" ;
    for(int i=0;i<3;i++){
        cout << stuArray[i] ;
    }
    cout << "------Students----" << endl;
    Course crs1("Kurs 1",stuArray,3);
    cout << crs1 ;
    crs1+=stundetToAdd;
    cout << crs1 ;
    crs1+=stundetToAdd;
    cout << crs1;
    cout << crs1[3].GetName() << endl;
   
}
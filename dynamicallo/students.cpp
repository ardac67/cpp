#include "students.h"
#include "course.h"
#include <iostream>
#include <algorithm>

namespace PA4 {

Student::Student() : name(""), ID(0), courses(nullptr), count(0) {}

Student::Student(std::string Name, int ID)
    : name(Name), ID(ID), courses(nullptr), count(0) {}

Student::~Student() {
    delete[] courses;
}
std::string Student::ReturnName(){
    return name;
}
void Student::ChangeName(const std::string& name){
    this->name=name;
}
int Student::ReturnID(){
    return ID;
}
void Student::ChangeID(int ID){
    (*this).ID=ID;
}
void Student::addCourse(Course & course){
    Course * temp = new Course[count+1];/*creating temp array*/
    for (int i = 0; i < count; i++) {
        temp[i] = courses[i];/*assinging into temp*/
    }
    temp[count]=course;/*adding new element*/
    
    delete[] courses;/*deleting old one*/
    courses = temp;/*assignin temp to the new one*/
    count=count+1;
}
void Student::addCourseToStudent(std::string name,std::string code){
    Course * temp = new Course[count+1];/*creating temp array*/
    for (int i = 0; i < count; i++) {
        temp[i] = courses[i];/*assigngin into temp*/
    }
    Course crs1(name,code);
    temp[count]=crs1;
    
    delete[] courses;/*deleting old one*/
    courses = temp;/*assignin temp to the new one*/
    count=count+1;

}
void Student::ListCourses(){
        std::cout << "0 up" << std::endl;
        for(int i=0;i<count;i++){
            std::cout << i+1 << " " << courses[i].ReturnName() << " " << courses[i].ReturnCode() << std::endl;
        }
    }
int Student::returnSize(){
    return count;
}
void Student::removeCourse(Course &course){
    int index = -1;
    for (int i = 0; i < count; ++i) {/*itereate through until the equality*/
        if (courses[i].ReturnName() == course.ReturnName()) {
            index = i;
            break;
        }
    }
    if (index != -1) {/*according to index removing element that index*/
        for (int i = index; i < count - 1; ++i) {
            courses[i] = courses[i + 1];
        }
        --count;
    }
}
Course & Student::returnIndexedCourse(int index){
    return courses[index];
}
Course * Student::returnCourses(){
        return courses;
}

}
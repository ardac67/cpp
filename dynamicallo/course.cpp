#include "course.h"
#include "students.h"
#include <iostream>
#include <algorithm>

namespace PA4 {

Course::Course() : name(""), code(""), students(nullptr), count(0) {}

Course::Course(const std::string& name, const std::string& code)
    : name(name), code(code), students(nullptr), count(0) {}

Course::~Course() {
    delete[] students;
}
std::string Course::ReturnName(){
    return name;
}
void Course::setName(const std::string& name){
    this->name=name;
}
std::string Course::ReturnCode(){
    return code;
}
void Course::setCode(const std::string& code){
    this->code=code;
}
int Course::size(){
    return count;
}
void Course::addStudent(Student& student){
    Student * temp = new Student[count+1];/*create temp dynamic array*/
    for (int i = 0; i < count; i++) {
        temp[i] = students[i];/*copy old stuff*/
    }
    temp[count]=student;/*then assign new stuff to the temp array*/
    delete[] students;/*delete old array*/
    students = temp;/*assing it to new array*/
    count=count+1;/*increment count*/
}
void Course::listStu(){
    for(int i=0;i<count;i++){
        std::cout << students[i].ReturnName() << " " << students[i].ReturnID() << std::endl;
    }
    
}
void Course::removeStudent(Student &student){
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (students[i].ReturnName() == student.ReturnName()) {/*iteretate through until the equality*/
            index = i;
            break;
        }
    }
    if (index != -1) {/*finded index is skipped then assinged to array into itself*/
        for (int i = index; i < count - 1; ++i) {
            students[i] = students[i + 1];
        }
        --count;
    }
}
}
#include "course.h"
#include "students.h"
#include "Sms.h"
#include <iostream>

namespace PA4 {

SchoolManagementSystem::SchoolManagementSystem(){
    students=nullptr;
    studentCount=0;
    courses=nullptr;
    courseCount=0;
}
SchoolManagementSystem::~SchoolManagementSystem(){
    delete [] students;
    delete [] courses;
}
void SchoolManagementSystem::addStudent(const std::string& name, int ID){
    Student newStudent(name, ID);/*new student objet*/
    Student* temp = new Student[studentCount + 1];/*temp array*/
    for (int i = 0; i < studentCount; ++i) {
        temp[i] = students[i];/*assinging temp array with old array*/
    }
    temp[studentCount] = newStudent;/*assingin new stuff into temp*/
    delete [] students;/*deleting old one*/
    students=temp;/*assinging temp into new one*/
    studentCount++;
}
void SchoolManagementSystem::removeStudent(int ID){
    int index = -1;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].ReturnID() == ID) {/*iterating until id is found*/
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < studentCount - 1; ++i) {/*founded index is swapped*/
            students[i] = students[i + 1];
        }
        --studentCount;
    }
}
void SchoolManagementSystem::addCourse(const std::string& name, const std::string& code){
    Course newCourse(name, code);/*new student objet*/
    Course* temp = new Course[courseCount + 1];/*temp array*/
    for (int i = 0; i < courseCount; ++i) {/*assinging temp array with old array*/
        temp[i] = courses[i];
    }
    temp[courseCount] = newCourse;/*deleting old one*/
    delete [] courses;
    courses=temp;/*assinging temp into new one*/
    courseCount++;
}
void SchoolManagementSystem::removeCourse(const std::string& code){
    int index = -1;
    for (int i = 0; i < courseCount; ++i) {/*iterate through until equality of code */
        if (courses[i].ReturnCode() == code) {
            index = i;
            break;
        }
    }
    if (index != -1) {/*swap founded index*/
        for (int i = index; i < courseCount - 1; ++i) {
            courses[i] = courses[i + 1];
        }
        --courseCount;
    }
}
Student & SchoolManagementSystem::findStudent(int ID){
    int index =0;
        for(int i=0;i<studentCount;i++){
            if(students[i].ReturnID()==ID){
                index=i;
                break;
            }
        }
        return students[index];
        
}
Course & SchoolManagementSystem::findCourse(const std::string& code){
    int index=0;
    for(int i=0;i<courseCount;i++){
        if(courses[i].ReturnCode()==code){
            index=i;
        }
    }
    return courses[index];
}
void SchoolManagementSystem::printAllStudents(){
    for(int i=0;i<studentCount;i++){
        std::cout << students[i].ReturnName() << " " << students[i].ReturnID() << std::endl;
    }
}
void SchoolManagementSystem::printAllCourses(){
    for(int i=0;i<courseCount;i++){
        std::cout << courses[i].ReturnName() << " " << courses[i].ReturnCode() << std::endl;
    }
}
void SchoolManagementSystem::printNotAllCourses(int id){
    bool find=false;
    std::cout << "0 up" << std::endl;
    for(int i=0;i<courseCount;i++){
        std::cout << i+1 << " "<< courses[i].ReturnName() << " " << courses[i].ReturnCode() << std::endl;
    }
}
Course & SchoolManagementSystem::returnIndexedCourse(int index){
    int i=0;
    if(courseCount>0){
        i=index;    
    }
    return courses[i];
}
bool SchoolManagementSystem::checkStuExistence(std::string name,int id){
    bool returnValue=false;
    for(int i=0;i<studentCount;i++){
        if(students[i].ReturnName()==name && students[i].ReturnID()==id){
            returnValue=true;
            break;
        }
        else returnValue=false;
    }
    return returnValue;
}
bool SchoolManagementSystem::checkCourseExistence(std::string name,std::string id){
  bool returnValue=false;
    for(int i=0;i<courseCount;i++){
        if(courses[i].ReturnName()==name && courses[i].ReturnCode()==id){
            returnValue=true;
            break;
        }
        else returnValue=false;
    }
    return returnValue;
}
}
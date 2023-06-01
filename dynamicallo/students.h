#pragma once
#include <string>

namespace PA4 {

class Course;  

class Student {
public:
    Student();/*default constructor*/
    Student(std::string Name, int ID);/*parametrized constructor*/
    ~Student();/*destructor*/

    std::string ReturnName();/*returns just name of the object*/
    void ChangeName(const std::string& name);/*changing name of the object*/

    int ReturnID() ;/*returns id of the object*/
    void ChangeID(int ID);/*changes id of the object*/
    int returnSize();/*returns size of the object*/
    void addCourse(Course & course);/*burası değişti*/
    void addCourseToStudent(std::string name,std::string code);/*used for adding course to student object*/
    void removeCourse(Course &course);/*removing course from student object takes course reference*/
    void ListCourses();/*just lists the course of object*/
    Course * returnCourses();/*returning courses array*/
    Course & returnIndexedCourse(int index);/*returns exact indexed course reference*/

private:
    std::string name;
    int ID;
    Course *courses;
    int count;
};

}  

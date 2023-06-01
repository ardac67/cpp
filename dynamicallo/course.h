#pragma once
#include <string>

namespace PA4 {

class Student;  

class Course {
public:
    Course();/*default constructor*/
    Course(const std::string& name, const std::string& code);/*parametrized constructor*/
    ~Course();/*destructor*/

    std::string ReturnName();/*member function returns name of student*/
    void setName(const std::string& name);/*setter function for setting name*/

    std::string ReturnCode();/*return student code*/
    void setCode(const std::string& code);/* setting the student code*/

    void addStudent(Student& student);/*adding student takes reference of student object*/
    void removeStudent(Student &student);/*removes student and takes reference of student object*/
    void listStu();/*listing students*/
    int size();/*returning size for further use*/
private:
    std::string name;
    std::string code;
    Student *students;/*student array*/
    int count;/*student array size*/
};

}  

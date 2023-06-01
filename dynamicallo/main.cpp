#include <iostream>
#include "students.h"
#include "course.h"
#include "Sms.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace PA4;
using namespace std;

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printMainMenu() {
    std::cout << "0 exit" << std::endl;
    std::cout << "1 student" << std::endl;
    std::cout << "2 course" << std::endl;
    std::cout << "3 list_all_students" << std::endl;
    std::cout << "4 list_all_courses" << std::endl;
}

void printStudentMenu() {
    std::cout << "0 up" << std::endl;
    std::cout << "1 add_student" << std::endl;
    std::cout << "2 select_student" << std::endl;
}

void printCourseMenu() {
    std::cout << "0 up" << std::endl;
    std::cout << "1 add_course" << std::endl;
    std::cout << "2 select_course" << std::endl;
}

int main() {
    SchoolManagementSystem sms;
    int choice;
    bool exit = false;
    bool validInput=false,validInput2=false,validInput3=false;
    while (!exit) {
        printMainMenu();
        std::cin >> choice;
        if (!(validInput = cin.good())) {/*char existence control*/
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice=-1;
		}
        clearInputBuffer();
        switch (choice) {
            case 0:
                exit = true;
                break;
            case 1: {
                bool studentMenuExit = false;
                while (!studentMenuExit) {
                    printStudentMenu();
                    int studentChoice;
                    std::cin >> studentChoice;
                    if (!(validInput2 = cin.good())) {/*char existence control*/
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        studentChoice=-1;
                    }
                    clearInputBuffer();
                    switch (studentChoice) {
                        case 0:
                            studentMenuExit = true;
                            break;
                        case 1: {
                            string firstName,lastName;
                            int ID;
                            cin >> firstName>>lastName>>ID;
                            string first_part=firstName+" "+lastName;
                            if(!sms.checkStuExistence(first_part,ID)){/*creating student*/
                                sms.addStudent(first_part, ID);
                            } 
                            break;
                        }
                        case 2: {
                            bool subMenuStudentExit=false;
                            while(!subMenuStudentExit){
                                string stName,stLastName;
                                int id;
                                cin >> stName >> stLastName >> id;
                                stName=stName+" "+stLastName;
                                int subStuChoice,notUp,notUp1;
                                if(!sms.checkStuExistence(stName,id)){/*checks student existance*/
                                    cout << "Not exists" << endl;
                                    break;
                                }
                                cout << "0 up" << endl;
                                cout << "1 delete_student" << endl;
                                cout << "2 add_selected_student_to_a_course" << endl;
                                cout << "3 drop_selected_student_from_a_course" << endl;
                                cin >> subStuChoice;
                                switch(subStuChoice){
                                    case 0:
                                        subMenuStudentExit=true;
                                    break;
                                    case 1:
                                        sms.removeStudent(id);/*removing student according to id*/
                                        subMenuStudentExit=true;
                                    break;
                                    case 2:
                                        sms.printNotAllCourses(id);/*printing all courses*/
                                        cin >> notUp;
                                        clearInputBuffer();
                                        if(notUp){
                                            sms.findStudent(id).addCourseToStudent(/*adding student to course*/
                                                sms.returnIndexedCourse(notUp-1).ReturnName()
                                                ,sms.returnIndexedCourse(notUp-1).ReturnCode()
                                                );
                                            sms.returnIndexedCourse(notUp-1).addStudent(sms.findStudent(id)); /*add course to student*/ 
                                            subMenuStudentExit=true;
                                        }
                                        else    
                                            subMenuStudentExit=true;
                                    break;
                                    case 3:
                                        sms.findStudent(id).ListCourses();
                                            cin >> notUp1;
                                            clearInputBuffer();
                                            if(notUp){
                                                sms.findStudent(id).removeCourse(/*removing course from student object*/
                                                    sms.findStudent(id)
                                                    .returnIndexedCourse(notUp1-1));
                                                sms.returnIndexedCourse(notUp1-1).removeStudent(sms.findStudent(id));/*removing student from course object*/
                                                subMenuStudentExit=true;    
                                            }
                                            else
                                                subMenuStudentExit=true;
                                        
                                        
                                    break;
                                    default:
                                    break;

                                }
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
                break;
            }
            case 2: {
                bool courseMenuExit = false;
                while (!courseMenuExit) {
                    printCourseMenu();
                    int courseChoice;
                    std::cin >> courseChoice;
                    clearInputBuffer();
                    switch (courseChoice) {
                        case 0:
                            courseMenuExit = true;
                            break;
                        case 1: {

                            std::string input_line;
                            std::getline(std::cin, input_line);
                            std::istringstream iss(input_line);
                            std::string code, name, temp;

                            iss >> code;

                            while (iss >> temp) {
                                if (!name.empty()) {
                                    name += " ";
                                }
                                name += temp;
                            }
                            if(!sms.checkCourseExistence(name,code)){
                                sms.addCourse(name,code);/*adding course to sms object and creating course*/
                            } 
                            break;
                        }
                        case 2: {
                            bool subMenuCourseExit=false;
                            string code,name;
                            while(!subMenuCourseExit){
                                std::string input_line;
                                std::getline(std::cin, input_line);
                                std::istringstream iss(input_line);
                                std::string code, name, temp;
                                iss >> code;


                                while (iss >> temp) {
                                    if (!name.empty()) {
                                        name += " ";
                                    }
                                    name += temp;
                                }
                                if(!sms.checkCourseExistence(name,code)){
                                    cout <<" course name is wrong "<< endl;
                                    continue;
                                }
                                else{
                                    int subCourseChoice;
                                    cout << "0 up" << endl;
                                    cout << "1 delete_course" << endl;
                                    cout << "2 list_students_registered_to_course" << endl;
                                    cin >> subCourseChoice;
                                    clearInputBuffer();
                                    switch (subCourseChoice)
                                    {
                                        case 0:
                                            subMenuCourseExit=true;
                                        break;
                                        case 1:
                                            sms.removeCourse(code);/*removing course according to code*/
                                            subMenuCourseExit=true;
                                        break;
                                        case 2:
                                            sms.findCourse(code).listStu();/*finding course and listing students that belongs to it*/
                                            subMenuCourseExit=true;
                                        default:
                                    
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
                break;
            }
            case 3:
                sms.printAllStudents();/*listing all students*/
                break;
            case 4:
                sms.printAllCourses();/* printing all courses*/
                break;
            default:
                break;
        }
    }

    return 0;
}



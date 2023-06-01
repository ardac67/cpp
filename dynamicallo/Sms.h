#include "students.h"
#include "course.h"

namespace PA4 {

class SchoolManagementSystem {
public:
    SchoolManagementSystem();/*default constructor*/
    ~SchoolManagementSystem();/*destructor*/

    void addStudent(const std::string& name, int ID);/*adding student to object*/
    void removeStudent(int ID);/*removing student from object*/

    void addCourse(const std::string& name, const std::string& code);/*adding course to object*/
    void removeCourse(const std::string& code);/*removing course from object*/

    Student & findStudent(int ID);/*returnin student reference from id*/
    Course & findCourse(const std::string& code);/*returning course from id*/

    void printAllStudents();/*printing existed student*/
    void printAllCourses();/*printing courses*/
    void printNotAllCourses(int id);/*printing not all but not belong to student courses*/
    bool checkStuExistence(std::string name,int id);/*checking student exists or not*/
    bool checkCourseExistence(std::string name,std::string id);/*checking course exists or not*/
    Course & returnIndexedCourse(int index);/*returning course reference according to the index*/
private:
    Student* students;
    int studentCount;
    Course* courses;
    int courseCount;
};

} 
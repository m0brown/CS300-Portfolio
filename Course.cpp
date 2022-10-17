#include "Course.h"

Course::Course() {

}

//Accessors
string Course::getCourseNumber() {
    return courseNumber;
}
string Course::getCourseName() {
    return courseName;
}
int Course::getCoursePrerequisitesSize() {
    return prerequisites.size();
}
string Course::getCoursePrerequisites(int index) {
    string value = " ";

    //Check if index is valid
    if (index >= 0 && index < prerequisites.size()) {
        value = prerequisites.at(index);
    }

    //If the index is out of bounds, returns empty string
    return value;
}

//Mutators
void Course::setCourseNumber(string number) {
    courseNumber = number;
}
void Course::setCourseName(string name) {
    courseName = name;
}
void Course::setCoursePrerequisites(string prereqs) {
    this->prerequisites.push_back(prereqs);
}
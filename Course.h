#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Course
{
    private:
        string courseNumber;
        string courseName;
        vector<string> prerequisites;

    public:
        //Constructor
        Course();

        //Accessors
        string getCourseNumber();
        string getCourseName();
        int getCoursePrerequisitesSize();
        string getCoursePrerequisites(int index);

        //Mutators
        void setCourseNumber(string number);
        void setCourseName(string name);
        void setCoursePrerequisites(string prereqs);
};


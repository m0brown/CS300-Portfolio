#pragma once
#include <iostream>
#include <string>

#include "Course.h"

using namespace std;

//Internal structure for tree node
struct Node {
    Course course;
    Node* left;
    Node* right;

    //Default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }
    //Initialize with a course
    Node(Course aCourse) :
        Node() {
        course = aCourse;
    }
};

//Binary Tree Class
class BST{
    private:
        Node* root;
    public:
        BST();
        void Insert(Course);
        void printAllCourses();
        void printAllCourses(Node* node);
        void printCourse(string courseNumber);
};


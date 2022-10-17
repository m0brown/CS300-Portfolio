#include "BST.h"

using namespace std;

BST::BST() {
    root = nullptr;
}

/* 
* Function to insert each Course object into the binary tree.
*/
void BST::Insert(Course course) {
    Node* newNode = new Node;
    newNode->course = course;
    newNode->left = nullptr;
    newNode->right = nullptr;

    //If the tree is empty, make the new node the root
    if (root == nullptr) {
        //Root is equal to the new node
        root = newNode;
    }
    //If the tree is not empty, find the correct position for the new node
    else {
        Node* current = root;
        Node* parent = nullptr;

        while (true) {
            parent = current;

            if (course.getCourseNumber() < current->course.getCourseNumber()) {
                current = current->left;
                if (current == nullptr) {
                    //Node becomes new left node
                    parent->left = newNode;
                    return;
                }
            }
            else {
                current = current->right;
                if (current == nullptr) {
                    //Node becomes new right node
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

/*
* Function to call printAllCourses with root.
*/
void BST::printAllCourses() {
    this->printAllCourses(this->root);
}

/*
* Function to print the courses in alphanumeric order from the BST.
*/
void BST::printAllCourses(Node* node) {
    if (node != nullptr) {
        //Visit left subtree
        this->printAllCourses(node->left);

        //Print course information
        cout << node->course.getCourseNumber() << ", " << node->course.getCourseName() << endl;

        //Visit right subtree
        this->printAllCourses(node->right);
    }
}

/*
* Function to print a course from user input.
*/
void BST::printCourse(string courseNumber) {
    cout << "Course Informaation:" << endl;
    //Set current node equal to root
    Node* current = root;

    //Loop to find the course in the BST
    while (current != nullptr) {
        //If the course is found, print it
        if (current->course.getCourseNumber() == courseNumber) {
            cout << current->course.getCourseNumber() << ", " << current->course.getCourseName() << endl;
            cout << "Prerequisites: ";
            //Loop to print the prerequisites
            for (int i = 0; i < current->course.getCoursePrerequisitesSize(); i++) {
                if (i > 0) cout << ", ";
                cout << current->course.getCoursePrerequisites(i);
            }
            //Print a new line
            cout << endl;
            return;
        }
        //If the course number is less than the current node, go left
        else if (courseNumber < current->course.getCourseNumber()) {
            current = current->left;
        }
        //If the course number is greater than the current node, go right
        else if (courseNumber > current->course.getCourseNumber()) {
            current = current->right;
        }
        //If the course is not found, print error message
        else if (current->course.getCourseNumber() != courseNumber) {
            cout << "Course not found." << endl;
            return;
        }
    }
    cout << endl;
}

/*
* Marysha Brown
* CS 300 Final Project
* 10-10-2022
* Advising Assistance software application to read a data file of courses from user input,
* parse the data and validate the courses, and load courses into a binary tree data structure.
* The user will then be able to print the course list in alphanumeric order and also search for
* a course to output it's details.
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>
#include<string>
#include<sstream>

#include "Course.h"
#include "BST.h"

using namespace std;

/*
* Function to load courses from CSV into Course object.
*/
BST loadCourses(string filePath) {
	BST courses;

	//Open the file
	ifstream file(filePath);

	//Throw error if file not found
	if (!file.is_open()) {
		throw runtime_error("Could not open file");
	}

	//Read data into vector
	if (file.is_open()) {
		string fileLine;

		//Read each line of the file
		while (getline(file, fileLine)) {

			//Stringstream of current line
			stringstream ss(fileLine);
			//Vector for tokens
			vector<string> token;

			//Tokenize current line
			while (ss.good()) {
				string lineString;
				getline(ss, lineString, ',');
				//Add tokens to token vector
				token.push_back(lineString);
			}

			//Add valid course to Course object
			if (token.size() >= 2) {
				//Create Course object
				Course course = Course();

				//Add tokens from token vector to Course object
				course.setCourseNumber(token[0]);
				course.setCourseName(token[1]);

				//Tokens after the first two are prerequisites
				for (int i = 2; i < token.size(); i++) {
					//Add prerequisites to prerequisite vector in Course object
					course.setCoursePrerequisites(token[i]);
				}
				//Insert the Course object into BST
				courses.Insert(course);
			}
		}
	}
	return courses;
	file.close();
}

int main() {
	string inputFile;
	string inputNumber;

	//Define binary search tree and Course object
	BST courses;
	Course course;

	int userChoice = 0;

	cout << "Welcome to the Course Planner" << endl;
	cout << endl;

	while (userChoice != 9) {
		cout << "--------------------" << endl;
		cout << "Menu Options:" << endl;
		cout << "  1. Load Courses" << endl;
		cout << "  2. Print Course List" << endl;
		cout << "  3. Print A Course" << endl;
		cout << "  9. Exit Program" << endl;
		cout << "--------------------" << endl;
		cout << "Enter your choice: ";

		cin >> userChoice;

		switch (userChoice) {
		case 1:
			//Get file from user
			cout << "Enter the name of the coures file to load: ";
			cin >> inputFile;
			cout << endl;
			cout << endl;
			cout << "Loading file..." << endl;
			courses = loadCourses(inputFile);
			cout << "CSV loaded and data is inserted into BST." << endl;
			cout << endl;
			break;
		case 2:
			cout << "Sample Schedule:" << endl;
			cout << endl;
			courses.printAllCourses();
			cout << endl;
			break;
		case 3:
			//Get course from user
			cout << "Enter the course number for more information: ";
			cin >> inputNumber;
			cout << endl;
			courses.printCourse(inputNumber);
			cout << endl;
			break;
		default:
			cout << userChoice << " is not a valid option. Please try again." << endl;
		}

	}
	cout << "Thank you, goodbye!" << endl;

	return 0;
}
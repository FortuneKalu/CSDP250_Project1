// CSDP250_Project1_LinkedList.cpp
// Name; Fortune Kalu
// ID: 1332172

#include <iostream>
#include "CourseList.h"
#include <limits>  // For input validation. I researched ways to efficiently input validate

using namespace std;

// Function to validate a 3-digit course code
int validateCourseCode();

// Function to validate credit hours (between 1 and 5)
int validateCreditHours();

// Function to validate grade (a single character)
char validateGrade();

// Function to display list and Delete Two Courses
void displayAndDeleteCourses(CourseList&);


// Function to display the menu
static void displayMenu() {
    cout << "--- Course List Menu ---\n";
    cout << "1. Add Course\n";
    cout << "2. Delete Course\n";
    cout << "3. Display Course List\n";
    cout << "4. Display List and Delete Two Courses\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    cout << "Welcome to Computer Science Course Management System.\n";
    CourseList courseList;
    int choice;

    // Menu-driven loop
    do {
        displayMenu();
        cin >> choice;

        // Validate the user's choice
        while (cin.fail()) {
            cin.clear();  // Clear input error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard bad input
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            displayMenu();
            cin >> choice;
        }

        if (choice == 1)
        {
            // Add a course
            cout << "Adding 10 new courses...\n";
            for (int i = 0; i < 10; i++) {
                cout << "Adding Course No. " << i + 1 << "...\n\n";
                int courseCode = validateCourseCode();
                int creditHours = validateCreditHours();
                char grade = validateGrade();
                courseList.addCourse(courseCode, creditHours, grade);
                cout << "Course No. " << i + 1 << " added successfully!\n";
            }   cout << endl;
        }

        else if (choice == 2)
        {
            // Delete a course
            if ((!courseList.isEmpty())) {
                cout << "Enter the course code to delete: ";
                int courseCode = validateCourseCode();
                courseList.deleteCourse(courseCode);
                cout << "Course deleted successfully (if it existed).\n";
            }
        }

        else if (choice == 3)
        {
            // Display the course list
            cout << "\nDisplaying all courses...\n";
            courseList.displayCourses();
        }

        else if (choice == 4) {
            cout << "Deleting two specfied courses...\n";
            displayAndDeleteCourses(courseList);
        }

        else if (choice == 5) {
            cout << "Exiting program...\n";
            return 0;
        }

        else
            cout << "Invalid option. Please choose a valid option.\n";

    } while (true);  // Exit the loop when the user chooses to exit
    return 0;
}


#include "CourseList.h"
#include <iostream>

using namespace std;

// Constructor: Initialize the head to nullptr
CourseList::CourseList() {
    head = nullptr;
}

// Destructor: Call the deleteAllNodes() function to free memory
CourseList::~CourseList() {
    deleteAllNodes();
}

// Function to add a course in increasing order by course code
void CourseList::addCourse(int courseCode, int creditHours, char grade) {
    CourseNode* newNode = new CourseNode(courseCode, creditHours, grade);

    // Insert at the beginning if the list is empty or the new node is smaller than head
    if (!head || head->courseCode > courseCode) {
        newNode->next = head;
        head = newNode;
    }
    else {
        // Traverse to find the correct position to insert the node
        CourseNode* nodeptr = head;
        while (nodeptr->next && nodeptr->next->courseCode < courseCode) {
            nodeptr = nodeptr->next;
        }
        newNode->next = nodeptr->next; // assign next node to new node pointer
        nodeptr->next = newNode; // place new node at correct position
    }
}

bool CourseList::isEmpty() {
    if (!head) {
        // List is empty
        cout << "The course list is empty.\n\n";
        return true;
    }
    else return false;
}

// Function to delete a course by course code
void CourseList::deleteCourse(int courseCode) {

    // Special case: the course to delete is the head
    if (head->courseCode == courseCode) {
        CourseNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Course deleted successfully.\n\n";
        return;
    }

    // Traverse to find the course to delete
    CourseNode* nodeptr = head;
    bool found = false;

    while (nodeptr->next && nodeptr->next->courseCode != courseCode) {
        nodeptr = nodeptr->next;
    }

    // Check if nodeptr->next is the node we want to delete
    if (nodeptr->next && nodeptr->next->courseCode == courseCode) {
        found = true;
        CourseNode* temp = nodeptr->next;
        nodeptr->next = nodeptr->next->next;  // Re-link the next pointer
        delete temp;  // Delete the found node
        cout << "Course deleted successfully.\n\n";
    }

    if (!found) {
        cout << "Course not found.\n\n";
    }
}


// Function to delete all nodes from the list
void CourseList::deleteAllNodes() {
    while (head) {
            CourseNode* temp = head;
            head = head->next;
            delete temp;
        }
}

// Function to display all courses in the list
void CourseList::displayCourses() const {
    CourseNode* nodeptr = head;
    if (!nodeptr) {
        cout << "No courses available.\n\n";
        return;
    }

    while (nodeptr) {
        cout << "\tCourse Code: " << nodeptr->courseCode
            << ", Credit Hours: " << nodeptr->creditHours
            << ", Grade: " << nodeptr->grade << endl;
        nodeptr = nodeptr->next;
    }
    cout << "\n";
}

char validateGrade() {
    char grade;
    while (true) {
        cout << "\tEnter Grade (single character): ";
        cin >> grade;
        if (cin.fail() || cin.get() != '\n') {  // Check if input is a single character
            cout << "\tInvalid input. Please enter a single character.\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        else {
            return grade;
        }
    }
}

int validateCreditHours() {
    int creditHours;
    while (true) {
        cout << "\tEnter Credit Hours (1 to 5): ";
        cin >> creditHours;
        if (cin.fail() || creditHours < 1 || creditHours > 5) {
            cout << "\tInvalid input. Please enter an integer between 1 and 5.\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        else {
            return creditHours;
        }
    }
}

int validateCourseCode() {
    int courseCode;
    while (true) {
        cout << "\tEnter Course Code (3 digits): ";
        cin >> courseCode;
        if (cin.fail() || courseCode < 100 || courseCode > 999) {
            cout << "\tInvalid input.Please enter a 3 - digit integer.\n";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        else {
            return courseCode;
        }
    }
}

void displayAndDeleteCourses(CourseList& courseList) {
    // Display the full list of courses before deletion
    cout << "\nDisplaying all courses before deletion:\n";
    courseList.displayCourses();

    // Delete two courses based on user input
    for (int n = 0; n < 2; n++) {
        int courseCode;
        cout << "Enter the Course Code of the course to delete: ";
        courseCode = validateCourseCode();  // Reuse the validation function for correct input
        courseList.deleteCourse(courseCode);
    }

    // Display the full list of courses after deletion
    cout << "\nDisplaying all courses after deletion:\n";
    courseList.displayCourses();
}
